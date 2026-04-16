//
// Created by arcyfields on 2026/4/16.
//

#include "rclcpp/rclcpp.hpp"
#include "robot_decision_n_vision/robot_vision.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions node_options;
    node_options.automatically_declare_parameters_from_overrides(true);
    rclcpp::spin(std::make_shared<robot_vision::VisionNode>(node_options));
    rclcpp::shutdown();
    return 0;
}