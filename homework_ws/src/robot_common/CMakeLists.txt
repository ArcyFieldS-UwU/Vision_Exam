cmake_minimum_required(VERSION 3.8)
project(robot_common)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_library(robot_common SHARED
        src/geometry_utils.cpp
        src/kalman_tracker.cpp
        src/image_utils.cpp
)

target_link_libraries(robot_common
        ${OpenCV_LIBRARIES}
)
target_include_directories(robot_common PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/robot_common>
)

install(TARGETS robot_common
        EXPORT export_robot_common
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/
        DESTINATION include/robot_common
)

install(EXPORT export_robot_common
        DESTINATION lib/cmake/robot_common
        NAMESPACE robot_common::
        FILE robot_commonTargets.cmake
)

ament_export_targets(export_robot_common HAS_LIBRARY_TARGET)
ament_export_dependencies(OpenCV)

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

ament_package()
