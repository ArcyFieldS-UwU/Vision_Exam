//
// Created by arcyfields on 2026/4/16.
//

#include "robot_decision_n_vision/robot_vision.hpp"

namespace robot_vision {
    VisionNode::VisionNode(const rclcpp::NodeOptions& options) : Node("vision_node", options),
                                                                 _param_handler(this){
        _image_sub = this->create_subscription<sensor_msgs::msg::Image>(
            "/image_raw", 10,
            [this] (const sensor_msgs::msg::Image & msg) {
                cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
                _img = cv_ptr->image;
            }
        );

        _enemies_data_sub = this->create_subscription<robot_interfaces::msg::ArmorArray>(
            "/enemies_data", 10,
            std::bind(& VisionNode::enemies_data_callback, this, std::placeholders::_1)
        );

        _is_debug = this->get_parameter("is_debug").as_bool();
        _is_showing_vel = this->get_parameter("show_vel").as_bool();
        _is_showing_acc = this->get_parameter("show_acc").as_bool();

        _debug_param_cb = _param_handler.add_parameter_callback(
            "is_debug",
            [this](const rclcpp::Parameter &param) {
                if (param.get_name() == "is_debug") {
                    _is_debug = param.as_bool();
                    RCLCPP_INFO(this->get_logger(), "Debug mode now %s", (_is_debug ? "ON" : "OFF"));
                    if (!_is_debug) {
                        cv::destroyAllWindows();
                    }
                }
            }
        );
        _vel_param_cb = _param_handler.add_parameter_callback(
            "show_vel",
            [this] (const rclcpp::Parameter & param) { _is_showing_vel = param.as_bool(); }
        );
        _acc_param_cb = _param_handler.add_parameter_callback(
            "show_acc",
            [this] (const rclcpp::Parameter & param) { _is_showing_acc = param.as_bool(); }
        );

        _last_log_time = this->now();
    }

    void VisionNode::enemies_data_callback(const robot_interfaces::msg::ArmorArray & enemies_data) {
        _enemies_data.clear();
        for (auto & enemy_ : enemies_data.armors) {
            robot_common::Armor armor(enemy_.id, cv::Point(enemy_.pos.x, enemy_.pos.y));
            armor.vel = cv::Point(enemy_.vel.x, enemy_.vel.y);
            armor.acc = cv::Point(enemy_.acc.x, enemy_.acc.y);
            _enemies_data.emplace_back(armor);
        }

        rclcpp::Time now = this->now();

        if (_is_debug) {
            cv::Mat _img_c = _img.clone();

            for (auto & enemy_ : _enemies_data) {
                if (_is_showing_vel) {
                    cv::arrowedLine(_img_c, enemy_.pos, enemy_.pos + enemy_.vel,
                        cv::Scalar(0, 0, 255), 3);
                }
                if (_is_showing_acc) {
                    cv::arrowedLine(_img_c, enemy_.pos, enemy_.pos + enemy_.acc,
                        cv::Scalar(255, 0, 0), 2);
                }
                if ((now - _last_log_time).seconds() > 10) {
                    if (_is_showing_vel) {
                        RCLCPP_INFO(this->get_logger(), "Enemy at (%d, %d) has vel valued %d.",
                            enemy_.pos.x, enemy_.pos.y, enemy_.vel.x
                        );
                    }
                    if (_is_showing_acc) {
                        RCLCPP_INFO(this->get_logger(), "Enemy at (%d, %d) has acc valued %d.",
                            enemy_.pos.x, enemy_.pos.y, enemy_.acc.x
                        );
                    }
                    _last_log_time = now;
                }
                cv::circle(_img_c, enemy_.pos, 3, cv::Scalar(0, 0, 255), 4);
            }

            cv::namedWindow("DEBUG_IMAGE", cv::WINDOW_KEEPRATIO);
            cv::resizeWindow("DEBUG_IMAGE", _img_c.cols / 3, _img_c.rows / 3);
            cv::imshow("DEBUG_IMAGE", _img_c);
            cv::waitKey(1);
        }
    }
}
