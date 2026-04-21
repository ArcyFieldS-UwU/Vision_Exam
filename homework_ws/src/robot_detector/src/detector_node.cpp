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

        _friends_data_pub = this->create_publisher<robot_interfaces::msg::ArmorArray>(
            "/friends_data", 10
        );
        _enemies_data_pub = this->create_publisher<robot_interfaces::msg::ArmorArray>(
            "/enemies_data", 10
        );

        _last_image_time = this->now();

        RCLCPP_INFO(this->get_logger(), "Detector is now ON.");
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

        rclcpp::Time now = this->now();
        double dt = (now - _last_image_time).seconds();
        _last_image_time = now;

        faction = check_faction(img);
        std::vector<cv::Point> friends, enemies;
        process_in_one_frame(img, faction, friends, enemies);

        robot_interfaces::msg::ArmorArray friends_data_to_pub;
        robot_interfaces::msg::ArmorArray enemies_data_to_pub;

        _tracker_friends.update(friends, dt);
        std::vector<robot_common::Armor> friends_data = _tracker_friends.get_data();
        for (auto & friend_ : friends_data) {
            robot_interfaces::msg::Armor armor;
            armor.id = friend_.id;

            armor.pos.x = friend_.pos.x;
            armor.pos.y = friend_.pos.y;

            armor.vel.x = friend_.vel.x;
            armor.vel.y = friend_.vel.y;

            armor.acc.x = friend_.acc.x;
            armor.acc.y = friend_.acc.y;

            armor.lost_count = friend_.lost_count;
            friends_data_to_pub.armors.emplace_back(armor);
        }
        _tracker_enemies.update(enemies, dt);
        std::vector<robot_common::Armor> enemies_data = _tracker_enemies.get_data();
        for (auto & enemy_ : enemies_data) {
            robot_interfaces::msg::Armor armor;
            armor.id = enemy_.id;

            armor.pos.x = enemy_.pos.x;
            armor.pos.y = enemy_.pos.y;

            armor.vel.x = enemy_.vel.x;
            armor.vel.y = enemy_.vel.y;

            armor.acc.x = enemy_.acc.x;
            armor.acc.y = enemy_.acc.y;

            armor.lost_count = enemy_.lost_count;
            enemies_data_to_pub.armors.emplace_back(armor);
        }

        now = this->now();

        friends_data_to_pub.dt = (now - _last_image_time).seconds();
        enemies_data_to_pub.dt = (now - _last_image_time).seconds();

        _friends_data_pub->publish(friends_data_to_pub);
        _enemies_data_pub->publish(enemies_data_to_pub);
    }
};