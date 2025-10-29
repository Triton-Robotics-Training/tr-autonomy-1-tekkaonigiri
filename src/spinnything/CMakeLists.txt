cmake_minimum_required(VERSION 3.8)
project(spinnything)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(predictedpos_pub src/predictedpos_pub.cpp)
ament_target_dependencies(predictedpos_pub rclcpp geometry_msgs)

install(TARGETS predictedpos_pub
  DESTINATION lib/${PROJECT_NAME})

ament_package()

