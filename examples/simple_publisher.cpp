#include "ros/ros.h"
#include "std_msgs/String.h"


int main(int argc, char **argv) // argumentos passados pelo terminal
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n; // objeto que cria os publishers, subscribers, services, etc

  ros::Publisher pub = n.advertise<std_msgs::String>("topic", 0); //topic, queue

  ros::Rate rate(10);

  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello, ROS";

    ROS_INFO("%s", msg.data.c_str());

    pub.publish(msg);
 
    ros::spinOnce();
 
    rate.sleep();
   }
   return 0;
 }