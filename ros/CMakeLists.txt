cmake_minimum_required(VERSION 3.5.1)

project(rosnode VERSION 0.1)

find_package(
    catkin REQUIRED COMPONENTS
    std_msgs
    geometry_msgs
    sensor_msgs
    gnss_msgs
)

find_package(Boost REQUIRED COMPONENTS system thread)

#catkin_package(
#    INCLUDE_DIR
#    LIBRARIES
#)

# Ros Node
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${catkin_INCLUDE_DIRS})
include_directories(${ROSLIB_INCLUDE_DIRS})
include_directories(${ROSCPP_INCLUDE_DIRS})
include_directories(${GNSS_MSGS_INCLUDE_DIRS})

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    ${Boost_LIBRARIES}
)