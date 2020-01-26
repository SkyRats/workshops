#include <ros/ros.h>

#include "tello.hpp"
#include "std_msgs/Empty.h"


Tello::Tello() {
    this->takeoff_pub = this->nh.advertise<std_msgs::Empty>("/tello/takeoff", 1);
    this->land_pub = this->nh.advertise<std_msgs::Empty>("/tello/land", 1);
}

Tello::~Tello() {
}

void Tello::takeoff() {
    takeoff_pub.publish(std_msgs::Empty());
}

void Tello::land() {
    land_pub.publish(std_msgs::Empty());
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "node");
    Tello* tellinho = new Tello();
    ros::Rate node_rate(60.0);
    for (int i = 0; i<20; i++) {
        tellinho->takeoff();
        node_rate.sleep();
    }
    ros::Duration(5).sleep();
    tellinho->land();

    return 0;
}