cmake_minimum_required(VERSION 3.8)
project(robot_detector)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(DEPENDENCIES
        rclcpp
        cv_bridge
        sensor_msgs
        OpenCV
        robot_common
        serial_port
        robot_interfaces
        std_msgs
)

foreach(DEPENDENCY ${DEPENDENCIES})
  find_package(${DEPENDENCY} REQUIRED)
endforeach()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(detector_node src/main.cpp src/detector_node.cpp)
target_link_libraries(detector_node
        ${OpenCV_LIBRARIES}
        robot_common::robot_common
        serial_port::serial_port
        serial_port::serialib
)
target_include_directories(detector_node PUBLIC
        include
        msg_serializer
)
ament_target_dependencies(detector_node ${DEPENDENCIES})

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

install(TARGETS detector_node
        DESTINATION lib/${PROJECT_NAME}
)

ament_package()
