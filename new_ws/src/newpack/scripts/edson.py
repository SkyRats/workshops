#!/usr/bin/env python

import rospy
from turtlesim.msg import Pose
from std_srvs.srv import Empty

posex = 0

def pose_cb(data):
  #sposex
  posex = data.x
  print(data.x)

rospy.init_node("edson")
sub = rospy.Subscriber("/turtle1/pose", Pose, pose_cb)
service = rospy.ServiceProxy("/clear", Empty)

def main():
  service()
  rospy.spin()


main()