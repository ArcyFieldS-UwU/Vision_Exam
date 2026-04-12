//
// Created by arcyfields on 2026/3/21.
//

#include "rclcpp/rclcpp.hpp"
#include "serial_port.h"
#include "kalman_filter_and_smth_else.h"

#include <vector>
#include <sensor_msgs/msg/image.hpp>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

bool IS_DEBUG = false;
bool IS_SHOWING_VEL = false;
bool IS_SHOWING_ACC = false;
bool IS_SHOWING_CONTOURS = false;
bool IS_SHOWING_COMPLETELY = false;

const cv::Point EMITTER_POS(576, 612);

const cv::Scalar LOWER_BOUND_OF_GRAY(140, 140, 140);
const cv::Scalar UPPER_BOUND_OF_GRAY(150, 150, 150);

inline int rect_sum(const cv::Mat & img_sum, const cv::Rect & rect) {
    int x0 = rect.x + rect.width, y0 = rect.y + rect.height;
    return img_sum.at<int>(rect.y, rect.x) + img_sum.at<int>(y0, x0)
         - img_sum.at<int>(y0, rect.x) - img_sum.at<int>(rect.y, x0);
}

class Homework : public rclcpp::Node {
public:
    Homework(std::string port) : Node("main_node"),
        _serial_port(std::make_unique<SerialPort>(port, 115200)) {
        _image_sub = this->create_subscription<sensor_msgs::msg::Image>(
            "/image_raw", 10,
            std::bind(&Homework::img_callback, this, std::placeholders::_1)
        );

        _last_fire_time = this->now();
        _last_image_time = this->now();
    };
private:
    std::unique_ptr<SerialPort> _serial_port;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr _image_sub;

    rclcpp::Time _last_fire_time;
    rclcpp::Time _last_image_time;

    Tracker _tracker_fri;
    Tracker _tracker_ene;
    std::mutex _data_mutex;

    bool check_faction(const cv::Mat & img) {
        static bool is_checked = false, faction = false;
        if (!is_checked) {
            is_checked = true;
            cv::Vec3b color = img.at<cv::Vec3b>(EMITTER_POS.y, EMITTER_POS.x);
            faction = color[0] > color[2];
            if (IS_DEBUG) {
                RCLCPP_INFO(this->get_logger(), "My faction is %s", (faction ? "BLUE" : "RED"));
            }
        }
        return faction;
    }

    void process_in_one_frame(const cv::Mat & img, const bool faction,
        std::vector<cv::Point> & friends, std::vector<cv::Point> & enemies) {
        cv::Mat gray_img, binary_img;
        cv::cvtColor(img, gray_img, CV_BGR2GRAY);
        cv::threshold(gray_img, binary_img, 100, 255, CV_THRESH_BINARY_INV);

        cv::Mat labels, stats, centroids;
        int n = cv::connectedComponentsWithStats(binary_img, labels, stats, centroids);

        cv::Mat img_sum_b, img_sum_r;
        {
            cv::Mat plane_b, plane_r;
            cv::extractChannel(img, plane_b, 0);
            cv::extractChannel(img, plane_r, 2);
            cv::integral(plane_b, img_sum_b, CV_32S);
            cv::integral(plane_r, img_sum_r, CV_32S);
        }

        friends.clear(), enemies.clear();

        for (int i = 1; i < n; i ++) {
            int left = stats.at<int>(i, cv::ConnectedComponentsTypes::CC_STAT_LEFT);
            int top = stats.at<int>(i, cv::ConnectedComponentsTypes::CC_STAT_TOP);
            int width = stats.at<int>(i, cv::ConnectedComponentsTypes::CC_STAT_WIDTH);
            int height = stats.at<int>(i, cv::ConnectedComponentsTypes::CC_STAT_HEIGHT);

            if (width < 64 || (top + height > 612)) {
                continue;
            }

            const int EDGE_WIDTH = 5;
            cv::Rect left_edge(left, top, EDGE_WIDTH, height);
            cv::Rect right_edge(left + width - EDGE_WIDTH, top, EDGE_WIDTH, height);

            cv::Mat ROI_left = img(left_edge);
            cv::Mat ROI_right = img(right_edge);

            cv::Mat mask_left, mask_right;
            inRange(ROI_left, LOWER_BOUND_OF_GRAY, UPPER_BOUND_OF_GRAY, mask_left);
            inRange(ROI_right, LOWER_BOUND_OF_GRAY, UPPER_BOUND_OF_GRAY, mask_right);

            if (cv::countNonZero(mask_left) > 0 || cv::countNonZero(mask_right) > 0) {
                continue;
            }

            int SOI_b = rect_sum(img_sum_b, left_edge) + rect_sum(img_sum_b, right_edge); // SOI := Sum Of Interested
            int SOI_r = rect_sum(img_sum_r, left_edge) + rect_sum(img_sum_r, right_edge);

            if ((SOI_b > SOI_r) != faction) {
                enemies.emplace_back(cv::Point(left + width / 2, top + height / 2));
            } else {
                friends.emplace_back(cv::Point(left + width / 2, top + height / 2));
            }
        }
    }

    void img_callback(const sensor_msgs::msg::Image & msg) {
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        cv::Mat img = cv_ptr->image;
        if (IS_DEBUG && img.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Cannot read the image.");
            return;
        }

        {
            std::lock_guard<std::mutex> lock(_data_mutex);
            rclcpp::Time now = this->now();
            double dt = (now - _last_image_time).seconds();
            _last_image_time = now;

            bool faction = check_faction(img);
            std::vector<cv::Point> friends, enemies;
            process_in_one_frame(img, faction, friends, enemies);

            _tracker_fri.update(friends, dt);
            std::vector<Armor> friends_data = _tracker_fri.get_data();
            _tracker_ene.update(enemies, dt);
            std::vector<Armor> enemies_data = _tracker_ene.get_data();
            if (enemies_data.empty() && !IS_SHOWING_COMPLETELY) {
                return;
            }

            std::vector<std::pair<cv::Point, cv::Point>> friends_pre_contours;
            friends_pre_contours.clear();
            now = this->now();
            if (!friends_data.empty()) {
                for (auto & armor : friends_data) {
                    get_pre_contours(armor, (now - _last_image_time).seconds(),
                        EMITTER_POS, friends_pre_contours);
                }
            }

            double best_dis = 1e5;
            cv::Point best_select(0, 0);
            for (auto & enemy : enemies_data) {
                cv::Point pre_ene = get_pre_ene(enemy, EMITTER_POS, (now - _last_image_time).seconds());

                bool is_friendly_fire = false;
                if (!friends_data.empty()) {
                    for (auto & contour : friends_pre_contours) {
                        is_friendly_fire |= check_cross(EMITTER_POS, pre_ene,
                            contour.first, contour.second);
                    }
                }
                if (is_friendly_fire) {
                    continue;
                }

                double dis = get_euclid_distance(EMITTER_POS, pre_ene);
                if (dis < best_dis) {
                    best_dis = dis;
                    best_select = pre_ene;
                }
            }
            if (best_select.x == 0 && best_select.y == 0 && !IS_SHOWING_COMPLETELY) {
                return;
            }

            std::pair<cv::Point, cv::Point> shooting_line;
            shooting_line.first = EMITTER_POS;
            shooting_line.second = best_select;

            now = this->now();
            if ((now - _last_fire_time).seconds() > 0.1) {
                double angle = atan2(best_select.y - EMITTER_POS.y, best_select.x - EMITTER_POS.x)
                             * (-180.0) / CV_PI;
                send_angle_com(angle);

                if (!(best_select.x == 0 && best_select.y == 0)) {
                    send_fire_com();
                    send_fire_com();
                    send_fire_com();
                }
                _last_fire_time = now;
            }
            if (IS_DEBUG) {
                cv::Mat img_c = img.clone();

                for (auto & fri : friends_data) {
                    if (IS_SHOWING_VEL) {
                        cv::arrowedLine(img_c, fri.pos, fri.pos + fri.vel,
                            cv::Scalar(0, 255, 0), 3);
                    }
                    if (IS_SHOWING_ACC) {
                        cv::arrowedLine(img_c, fri.pos, fri.pos + fri.acc,
                            cv::Scalar(255, 0, 0), 2);
                    }
                    cv::circle(img_c, fri.pos, 3, cv::Scalar(0, 255, 0), 4);
                }
                for (auto & ene : enemies_data) {
                    if (IS_SHOWING_VEL) {
                        cv::arrowedLine(img_c, ene.pos, ene.pos + ene.vel,
                            cv::Scalar(0, 0, 255), 3);
                    }
                    if (IS_SHOWING_ACC) {
                        cv::arrowedLine(img_c, ene.pos, ene.pos + ene.acc,
                            cv::Scalar(255, 0, 0), 2);
                    }
                    cv::circle(img_c, ene.pos, 3, cv::Scalar(0, 0, 255), 4);
                }
                if (IS_SHOWING_CONTOURS) {
                    for (auto & contour : friends_pre_contours) {
                        cv::line(img_c, contour.first, contour.second,
                            cv::Scalar(0, 255, 0), 3);
                    }
                    if (!(best_select.x == 0 && best_select.y == 0)) {
                        cv::line(img_c, shooting_line.first, shooting_line.second,
                            cv::Scalar(255, 0, 0), 3);
                    }
                }

                cv::namedWindow("DEBUG_IMAGE", cv::WINDOW_KEEPRATIO);
                cv::imshow("DEBUG_IMAGE", img_c);
                cv::waitKey(1);
            }
        }
    }
    void send_angle_com(const double angle) {
        uint8_t buffer[5];
        buffer[0] = 0x01;
        float angle_f = static_cast<float>(angle);
        memcpy(buffer + 1, & angle_f, 4);
        _serial_port->write(buffer, 5);
    }
    void send_fire_com() {
        uint8_t buffer[1] = {0x02};
        _serial_port->write(buffer, 1);
    }
};

int main(int argc, char *argv[]) {
    std::ifstream infile("port.txt");
    if (!infile) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(infile, line)) {
        lines.emplace_back(line);
        if (line.compare("DEBUG") == 0) {
            IS_DEBUG = true;
        } else if (line.compare("SHOWING_VEL") == 0) {
            IS_SHOWING_VEL = true;
        } else if (line.compare("SHOWING_ACC") == 0) {
            IS_SHOWING_ACC = true;
        } else if (line.compare("SHOWING_CONTOURS") == 0) {
            IS_SHOWING_CONTOURS = true;
        } else if (line.compare("SHOWING_COMPLETELY") == 0) {
            IS_SHOWING_COMPLETELY = true;
        }
    }

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Homework>(lines[0]));
    rclcpp::shutdown();
    return 0;
}