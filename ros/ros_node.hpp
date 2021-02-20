#pragma once

#include <ros/ros.h>
#include <gnss_msgs/GnssImuInfo.h>
#include <gnss_msgs/GnssInfo.h>

#include "asio.threadpool.hpp"

class RosNode : public AsioThreadPool {
public:
    RosNode(ros::NodeHandle nh) : AsioThreadPool(3){
        __gnss_pub = nh.advertise<gnss_msgs::GnssInfo>("/ins/gnss", 1);
        __imu_pub = nh.advertise<gnss_msgs::GnssImuInfo>("/ins/imu", 1);
    }
    ~RosNode() {};

    void try_pub() {
        gnss_msgs::GnssImuInfo imu_msg;
        imu_msg.header.stamp = 
    }

private:
    ros::Publisher __gnss_pub;
    ros::Publisher __imu_pub;
};

