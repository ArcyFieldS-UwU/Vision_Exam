cmake_minimum_required(VERSION 3.8)
project(robot_decision_n_vision)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(DEPENDENCIES
        rclcpp
        cv_bridge
        OpenCV
        serial_port
        robot_interfaces
        robot_common
        std_msgs
        sensor_msgs
)

foreach(DEPENDENCY ${DEPENDENCIES})
  find_package(${DEPENDENCY} REQUIRED)
endforeach()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(vision_node src/robot_vision.cpp src/vision.cpp)
add_executable(decision_node src/robot_decision.cpp src/decision.cpp)
target_link_libraries(vision_node
        ${OpenCV_LIBRARIES}
)
target_link_libraries(decision_node
        ${OpenCV_LIBRARIES}
        robot_common::robot_common
)
target_include_directories(vision_node PUBLIC
        include
)
target_include_directories(decision_node PUBLIC
        include
)
ament_target_dependencies(vision_node OpenCV cv_bridge robot_interfaces robot_common rclcpp sensor_msgs)
ament_target_dependencies(decision_node OpenCV robot_interfaces serial_port robot_common rclcpp std_msgs)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(
        DIRECTORY config
        DESTINATION share/${PROJECT_NAME}
)

install(
        TARGETS vision_node decision_node
        DESTINATION lib/${PROJECT_NAME}
)

ament_package()
