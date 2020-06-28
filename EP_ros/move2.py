#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

start_x = 0
start_y = 0
start_theta = 0

def callback(data):
    global start_x, start_y, start_theta
    start_x = data.x
    start_y = data.y
    start_theta = data.theta

def distance(pose, goal_pose):
    return math.sqrt((goal_pose.x - pose.x) * (goal_pose.x - pose.x) + (goal_pose.y - pose.y) * (goal_pose.y - pose.y)) 

def angle(pose, goal_pose):
    return math.atan2(goal_pose.y - pose.y, goal_pose.x - pose.x)


def moveToGoal():
    
    rospy.init_node("gotogoal")
    velocity_publisher = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size = 10)
    pose_subscriber = rospy.Subscriber("/turtle1/pose", Pose, callback)    
    rate = rospy.Rate(10)
    
    pose = Pose()

    # Goal pose
    goal_pose = Pose()
    goal_pose.x = float(input("Set your x goal: "))
    goal_pose.y = float(input("Set your y goal: "))

    vel = Twist()

    pose.x = round(start_x, 2)
    pose.y = round(start_y, 2)
    pose.theta = start_theta

    while distance(pose, goal_pose) >= 0.1:
        
        pose.x = round(start_x, 2)
        pose.y = round(start_y, 2)
        pose.theta = start_theta

        # Set velocity
        vel.linear.x = 1.5 * distance(pose, goal_pose)
        vel.angular.z = 6 * (angle(pose, goal_pose) - pose.theta)

        velocity_publisher.publish(vel)
        rate.sleep()

    # When get out, is near the goal pose
    vel.linear.x = 0
    vel.angular.z = 0
    velocity_publisher.publish(vel)
    #print(vel.angular.z)

#=====

if __name__ == '__main__':
    try:
        go = input("Set a position? (yes=1/ no=0): ")
        while (go == 1):
            moveToGoal()
            go = input("Set a position? (yes=1 / no=0): ")
    except rospy.ROSInterruptException:
        pass