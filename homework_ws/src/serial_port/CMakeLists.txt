cmake_minimum_required(VERSION 3.8)
project(serial_port)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_library(serial_port SHARED
        src/serial_port.cpp
)

include_directories(
        include
        msg_serializer
        thirdparty/serialib
)

add_subdirectory(
        thirdparty/serialib
)

target_include_directories(serial_port PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/msg_serializer>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/serialib>
        $<INSTALL_INTERFACE:include/serial_port>
        $<INSTALL_INTERFACE:include/msg_serializer>
        $<INSTALL_INTERFACE:include/thirdparty/serialib>
)

install(TARGETS serial_port
        EXPORT export_serial_port
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

install(TARGETS serialib
        EXPORT export_serial_port
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY include/
        DESTINATION include/serial_port
)
install(DIRECTORY msg_serializer/
        DESTINATION include/msg_serializer
)
install(DIRECTORY thirdparty/serialib/
        DESTINATION include/thirdparty/serialib
)

install(EXPORT export_serial_port
        DESTINATION lib/cmake/serial_port
        NAMESPACE serial_port::
        FILE serial_portTargets.cmake
)

ament_export_targets(export_serial_port HAS_LIBRARY_TARGET)

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
