//
// Created by arcyfields on 2026/4/14.
//

#include "robot_detector/detector_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::NodeOptions node_options;
    node_options.automatically_declare_parameters_from_overrides(true);
    rclcpp::spin(std::make_shared<robot_detector::DetectorNode>());
    rclcpp::shutdown();
    return 0;
}