//
// Created by arcyfields on 2026/4/16.
//

#include "robot_decision_n_vision/robot_decision.hpp"

const cv::Point EMITTER_POS(576, 612);

message_data angle_msg_data {
    float angle_f = 0.;
} angle_msg;
message_data fire_msg_data {

} fire_msg;

namespace robot_decider {
    DecisionNode::DecisionNode(const rclcpp::NodeOptions& options) : Node("decision_node", options),
                                                                     _param_handler(this) {
        _fri_data_sub = this->create_subscription<robot_interfaces::msg::ArmorArray>(
            "/fri_data", 10,
            std::bind(& DecisionNode::fri_data_callback, this, std::placeholders::_1)
        );
        _ene_data_sub = this->create_subscription<robot_interfaces::msg::ArmorArray>(
            "/ene_data", 10,
            std::bind(& DecisionNode::ene_data_callback, this, std::placeholders::_1)
        );
        _port_switch_pub = this->create_publisher<std_msgs::msg::Empty>("/port_switch", 10);

        std::string port = this->get_parameter("serial_port").as_string();
        _serial_port = std::make_shared<robot::RobotSerial>(port, 115200);
        _serial_port->spin(true);
        RCLCPP_INFO(this->get_logger(), "The serial port has been opened on %s.", port.c_str());

        _serial_port_cb = _param_handler.add_parameter_callback(
            "serial_port",
            [this] (const rclcpp::Parameter & param) {
                std::string new_port = param.as_string();
                try {
                    auto new_port_ptr = std::make_shared<robot::RobotSerial>(new_port, 115200);
                    new_port_ptr->spin(true);
                    std::atomic_store(& _serial_port, new_port_ptr);
                    RCLCPP_INFO(this->get_logger(), "The serial port has been switched to %s.", new_port.c_str());
                    std_msgs::msg::Empty signal;
                    _port_switch_pub->publish(signal);
                } catch (std::exception & e) {
                    RCLCPP_ERROR(this->get_logger(), "Failed to switch the serial port: %s", e.what());
                }
            }
        );

        _last_fire_time = this->now();
    }

    void DecisionNode::fri_data_callback(const robot_interfaces::msg::ArmorArray & fri_data) {
        _friends_data.clear();
        for (auto & fri : fri_data.armors) {
            robot_common::Armor armor(fri.id, cv::Point(fri.pos.x, fri.pos.y));
            armor.vel = cv::Point(fri.vel.x, fri.vel.y);
            armor.acc = cv::Point(fri.acc.x, fri.acc.y);
            _friends_data.emplace_back(armor);
        }

        double dt = fri_data.dt;
        _friends_pre_contours.clear();
        if (!_friends_data.empty()) {
            for (auto & armor : _friends_data) {
                robot_common::get_pre_contours(armor, dt, EMITTER_POS, _friends_pre_contours);
            }
        }
    }
    void DecisionNode::ene_data_callback(const robot_interfaces::msg::ArmorArray & ene_data) {
        auto port = std::atomic_load(& _serial_port);
        _enemies_data.clear();
        for (auto & ene : ene_data.armors) {
            robot_common::Armor armor(ene.id, cv::Point(ene.pos.x, ene.pos.y));
            armor.vel = cv::Point(ene.vel.x, ene.vel.y);
            armor.acc = cv::Point(ene.acc.x, ene.acc.y);
            _enemies_data.emplace_back(armor);
        }

        double best_dis = 1e5, dt = ene_data.dt;
        cv::Point best_select(0, 0);
        for (auto & enemy : _enemies_data) {
            cv::Point pre_ene = robot_common::get_pre_ene(enemy, EMITTER_POS, dt);

            bool is_friendly_fire = false;
            if (!_friends_data.empty()) {
                for (auto & contour : _friends_pre_contours) {
                    is_friendly_fire |= robot_common::is_intersectant(EMITTER_POS, pre_ene,
                        contour.first, contour.second);
                }
            }
            if (is_friendly_fire) {
                continue;
            }

            double dis = robot_common::get_euclidean_distance(EMITTER_POS, pre_ene);
            if (dis < best_dis) {
                best_dis = dis;
                best_select = pre_ene;
            }
        }
        if (best_select.x == 0 && best_select.y == 0) {
            return;
        }

        rclcpp::Time now = this->now();
        if ((now - _last_fire_time).seconds() > 0.1) {
            double angle = atan2(best_select.y - EMITTER_POS.y, best_select.x - EMITTER_POS.x)
                         * (-180.0) / CV_PI;
            angle_msg.angle_f = static_cast<float>(angle);
            port->write(0x01, angle_msg);

            usleep(5000);
            port->write(0x02, fire_msg);
            port->write(0x02, fire_msg);
            port->write(0x02, fire_msg);
            _last_fire_time = now;
        }
    }
}
