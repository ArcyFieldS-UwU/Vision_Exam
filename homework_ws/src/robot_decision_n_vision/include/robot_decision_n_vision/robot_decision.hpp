//
// Created by arcyfields on 2026/4/16.
//

#ifndef HOMEWORK_BRINGUP_ROBOT_DECISION_HPP
#define HOMEWORK_BRINGUP_ROBOT_DECISION_HPP

#include "rclcpp/rclcpp.hpp"
#include "serialPro/robotComm.h"
#include "robot_interfaces/msg/armor_array.hpp"
#include "robot_common/geometry_utils.hpp"
#include "robot_common/kalman_tracker.hpp"

#include <std_msgs/msg/empty.hpp>
#include <opencv2/opencv.hpp>

namespace robot_decider {
    class DecisionNode : public rclcpp::Node {
    public:
        DecisionNode(const rclcpp::NodeOptions & options);
    private:
        rclcpp::Subscription<robot_interfaces::msg::ArmorArray>::SharedPtr _friends_data_sub;
        rclcpp::Subscription<robot_interfaces::msg::ArmorArray>::SharedPtr _enemies_data_sub;

        rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr _port_switch_pub;

        std::shared_ptr<robot::RobotSerial> _serial_port;
        std::shared_ptr<rclcpp::ParameterCallbackHandle> _serial_port_cb;

        rclcpp::ParameterEventHandler _param_handler;

        std::vector<robot_common::Armor> _friends_data;
        std::vector<robot_common::Armor> _enemies_data;
        std::vector<std::pair<cv::Point, cv::Point>> _friends_pre_contours;

        rclcpp::Time _last_fire_time;

        void friends_data_callback(const robot_interfaces::msg::ArmorArray & friends_data);
        void enemies_data_callback(const robot_interfaces::msg::ArmorArray & enemies_data);
    };
}


#endif //HOMEWORK_BRINGUP_ROBOT_DECISION_HPP
