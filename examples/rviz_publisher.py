import rospy
import numpy as np
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Pose, Vector3
from std_msgs.msg import ColorRGBA


class MarkerPub:
    def __init__(self):
        self.visual_marker_pub = rospy.Publisher('/visualization_marker', Marker, queue_size=10)
    

        self.rate = rospy.Rate(60)


        self.current_pose_marker = Marker()

        self.current_pose_marker.header.frame_id = "map"
        self.current_pose_marker.ns = "/"
        self.current_pose_marker.id = 0
        self.current_pose_marker.type = Marker.SPHERE
        self.current_pose_marker.action = Marker.MODIFY
        self.current_pose_marker.scale = Vector3(0.1, 0.1, 0.1)
        self.current_pose_marker.color = ColorRGBA(r=0, g=1, b=0, a=0.9)
        self.current_pose_marker.lifetime = rospy.Duration(secs=10)

    def set_pose(self, x, y, z):
        goal = Pose()
        goal.position.x = x
        goal.position.y = y
        goal.position.z = z
        self.current_pose_marker.pose = goal
        self.current_pose_marker.id += 1
        self.current_pose_marker.header.stamp = rospy.Time()

        self.visual_marker_pub.publish(self.current_pose_marker)


def main():
    rospy.init_node("marker_pub")
    mark = MarkerPub()
    theta=0
    STEP = 0.01
    while not rospy.is_shutdown():
        rospy.loginfo("Publishing position " + str(mark.current_pose_marker.pose))
        mark.set_pose(np.sin(theta), np.cos(theta), np.sqrt(theta)+(1/(theta+0.25))-1)
        theta += STEP
        STEP *= 1.01
        mark.rate.sleep()

if __name__ == "__main__":
    main()