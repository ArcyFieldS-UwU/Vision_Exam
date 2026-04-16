//
// Created by arcyfields on 2026/4/14.
//

#ifndef ROBOT_DETECTOR_DETECTOR_NODE_HPP
#define ROBOT_DETECTOR_DETECTOR_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "robot_common/kalman_tracker.hpp"
#include "robot_common/geometry_utils.hpp"
#include "robot_common/image_utils.hpp"
#include "serialPro/robotComm.h"
#include "robot_interfaces/msg/armor.hpp"
#include "robot_interfaces/msg/armor_array.hpp"

#include <vector>
#include <sensor_msgs/msg/image.hpp>
#include <std_msgs/msg/empty.hpp>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

namespace robot_detector {
    class DetectorNode : public rclcpp::Node {
    public:
        explicit DetectorNode();
    private:
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr _image_sub;
        rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr _port_switch_sub;
        rclcpp::Publisher<robot_interfaces::msg::ArmorArray>::SharedPtr _fri_data_pub;
        rclcpp::Publisher<robot_interfaces::msg::ArmorArray>::SharedPtr _ene_data_pub;

        robot_common::Tracker _tracker_fri;
        robot_common::Tracker _tracker_ene;

        rclcpp::Time _last_image_time;

        std::mutex _data_mutex;

        bool is_checked = false;
        bool faction = false;

        bool check_faction(const cv::Mat & img);

        void process_in_one_frame(const cv::Mat & img, const bool faction,
            std::vector<cv::Point> & friends, std::vector<cv::Point> & enemies);

        void img_callback(const sensor_msgs::msg::Image & msg);
    };
}

#endif //ROBOT_DETECTOR_DETECTOR_NODE_HPP
