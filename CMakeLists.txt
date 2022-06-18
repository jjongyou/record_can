cmake_minimum_required(VERSION 3.8)
project(record_can)


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ichthus_msgs REQUIRED)

include_directories(include)

add_library(can_record STATIC src/can_record.cpp)
target_compile_features(can_record PRIVATE cxx_std_17)
ament_target_dependencies(can_record rclcpp
  ichthus_msgs)
target_include_directories(can_record
  PUBLIC
  # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  # $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

add_executable(record_node src/record_node.cpp)
ament_target_dependencies(record_node rclcpp)
target_link_libraries(record_node can_record)

install(TARGETS
  record_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
