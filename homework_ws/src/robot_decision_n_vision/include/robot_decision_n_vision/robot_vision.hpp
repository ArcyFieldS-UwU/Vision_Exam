//
// Created by arcyfields on 2026/4/16.
//

#ifndef HOMEWORK_BRINGUP_ROBOT_VISION_HPP
#define HOMEWORK_BRINGUP_ROBOT_VISION_HPP

#include "rclcpp/rclcpp.hpp"
#include "robot_interfaces/msg/armor_array.hpp"
#include "robot_common/kalman_tracker.hpp"
#include "sensor_msgs/msg/image.hpp"

#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

namespace robot_vision {
    class VisionNode : public rclcpp::Node {
    public:
        VisionNode(const rclcpp::NodeOptions& options);
    private:
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr _image_sub;

        rclcpp::Subscription<robot_interfaces::msg::ArmorArray>::SharedPtr _enemies_data_sub;

        rclcpp::ParameterEventHandler _param_handler;

        rclcpp::Time _last_log_time;

        std::vector<robot_common::Armor> _enemies_data;

        cv::Mat _img;

        bool _is_debug;
        bool _is_showing_vel;
        bool _is_showing_acc;
        std::shared_ptr<rclcpp::ParameterCallbackHandle> _debug_param_cb;
        std::shared_ptr<rclcpp::ParameterCallbackHandle> _vel_param_cb;
        std::shared_ptr<rclcpp::ParameterCallbackHandle> _acc_param_cb;

        void enemies_data_callback(const robot_interfaces::msg::ArmorArray & enemies_data);
    };
}

#endif //HOMEWORK_BRINGUP_ROBOT_VISION_HPP
