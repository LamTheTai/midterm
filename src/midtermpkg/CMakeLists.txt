cmake_minimum_required(VERSION 3.0.2)
project(midtermpkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)



catkin_package(
  INCLUDE_DIRS include
  LIBRARIES midtermpkg
  CATKIN_DEPENDS roscpp rospy std_msgs
  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(wall_following src/wall_following.cpp)
add_executable(call_4turtle src/call_4turtle.cpp)

target_link_libraries(wall_following
  ${catkin_LIBRARIES}
)
target_link_libraries(call_4turtle
  ${catkin_LIBRARIES}
)



