//
// Created by arcyfields on 2026/4/14.
//

#include "robot_detector/detector_node.hpp"

const cv::Point EMITTER_POS(576, 612);

namespace robot_detector {
    DetectorNode::DetectorNode() : Node("detector_node") {
        _image_sub = this->create_subscription<sensor_msgs::msg::Image>(
            "/image_raw", 10,
            std::bind(& DetectorNode::img_callback, this, std::placeholders::_1)
        );
        _port_switch_sub = this->create_subscription<std_msgs::msg::Empty>(
            "/port_switch", 10,
            [this] (const std_msgs::msg::Empty & ) { is_checked = false; }
        );

        _fri_data_pub = this->create_publisher<robot_interfaces::msg::ArmorArray>("/fri_data", 10);
        _ene_data_pub = this->create_publisher<robot_interfaces::msg::ArmorArray>("/ene_data", 10);

        _last_image_time = this->now();
    };

    bool DetectorNode::check_faction(const cv::Mat & img) {
        if (!is_checked) {
            is_checked = true;
            cv::Vec3b color = img.at<cv::Vec3b>(EMITTER_POS.y, EMITTER_POS.x);
            faction = color[0] > color[2];
            RCLCPP_INFO(this->get_logger(), "My faction is %s", (faction ? "BLUE" : "RED"));
        }
        return faction;
    }

    void DetectorNode::process_in_one_frame(const cv::Mat & img, const bool faction,
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

            if (robot_common::is_have_gray(img, left_edge) || robot_common::is_have_gray(img, right_edge)) {
                continue;
            }

            int SOI_b = robot_common::rect_sum(img_sum_b, left_edge) +
                robot_common::rect_sum(img_sum_b, right_edge); // SOI := Sum Of Interested
            int SOI_r = robot_common::rect_sum(img_sum_r, left_edge) +
                robot_common::rect_sum(img_sum_r, right_edge);

            if ((SOI_b > SOI_r) != faction) {
                enemies.emplace_back(cv::Point(left + width / 2, top + height / 2));
            } else {
                friends.emplace_back(cv::Point(left + width / 2, top + height / 2));
            }
        }
    }

    void DetectorNode::img_callback(const sensor_msgs::msg::Image & msg) {
        cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        cv::Mat img = cv_ptr->image;
        if (img.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Cannot read the image.");
            return;
        }

        {
            std::lock_guard<std::mutex> lock(_data_mutex);
            rclcpp::Time now = this->now();
            double dt = (now - _last_image_time).seconds();
            _last_image_time = now;

            faction = check_faction(img);
            std::vector<cv::Point> friends, enemies;
            process_in_one_frame(img, faction, friends, enemies);

            robot_interfaces::msg::ArmorArray fri_data_to_pub;
            robot_interfaces::msg::ArmorArray ene_data_to_pub;

            _tracker_fri.update(friends, dt);
            std::vector<robot_common::Armor> friends_data = _tracker_fri.get_data();
            for (auto & fri : friends_data) {
                robot_interfaces::msg::Armor armor;
                armor.id = fri.id;

                armor.pos.x = fri.pos.x;
                armor.pos.y = fri.pos.y;

                armor.vel.x = fri.vel.x;
                armor.vel.y = fri.vel.y;

                armor.acc.x = fri.acc.x;
                armor.acc.y = fri.acc.y;

                armor.lost_count = fri.lost_count;
                fri_data_to_pub.armors.emplace_back(armor);
            }
            _tracker_ene.update(enemies, dt);
            std::vector<robot_common::Armor> enemies_data = _tracker_ene.get_data();
            for (auto & ene : enemies_data) {
                robot_interfaces::msg::Armor armor;
                armor.id = ene.id;

                armor.pos.x = ene.pos.x;
                armor.pos.y = ene.pos.y;

                armor.vel.x = ene.vel.x;
                armor.vel.y = ene.vel.y;

                armor.acc.x = ene.acc.x;
                armor.acc.y = ene.acc.y;

                armor.lost_count = ene.lost_count;
                ene_data_to_pub.armors.emplace_back(armor);
            }

            now = this->now();

            fri_data_to_pub.dt = (now - _last_image_time).seconds();
            ene_data_to_pub.dt = (now - _last_image_time).seconds();

            _fri_data_pub->publish(fri_data_to_pub);
            _ene_data_pub->publish(ene_data_to_pub);
        }
    }
};