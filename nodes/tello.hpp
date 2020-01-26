#include <ros/ros.h>

#include "std_msgs/Empty.h"

#include "geometry_msgs/Twist.h"

#include <string>

using namespace std;

class Tello {
public:
    string name;
    

    Tello();
    ~Tello();
    void takeoff();
    void land();
protected:
    ros::Publisher takeoff_pub;
    ros::Publisher land_pub;
    ros::NodeHandle nh;
    };
