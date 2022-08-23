cmake_minimum_required(VERSION 3.0.2)
project(pwm_thrust_calib)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable( pwm_thrust_calib_node src/main.cpp )
target_link_libraries( pwm_thrust_calib_node ${catkin_LIBRARIES})