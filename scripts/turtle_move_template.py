import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

TOL = 1

class TurtleMover(Node):

    def __init__(self):
        super().__init__('turtle_mover')
        self._vel_publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.pose_subscriber = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)

        self._turtle_pose = Pose()

    def pose_callback(self, msg):
        self._turtle_pose = msg
        self.get_logger().info('Recebi uma mensagem!')

    def set_position(self, x, y, theta):
        msg = Twist()
        rclpy.spin_once(self)

        msg.angular.z = 0.2
        dist = abs(0 - self._turtle_pose.theta)
        while dist >= TOL/2:
            rclpy.spin_once(self)
            self._vel_publisher.publish(msg)
            dist = abs(0 - self._turtle_pose.theta)
        msg.angular.z = 0.0

        msg.linear.x = (x - self._turtle_pose.x)/abs(x - self._turtle_pose.x + 1)
        dist = abs(x - self._turtle_pose.x)
        while dist >= TOL:
            rclpy.spin_once(self)
            self._vel_publisher.publish(msg)
            dist = abs(x - self._turtle_pose.x)
        msg.linear.x = 0.0

        msg.linear.y = (y - self._turtle_pose.y)/abs(y - self._turtle_pose.y + 1)
        dist = abs(y - self._turtle_pose.y)
        while dist >= TOL:
            rclpy.spin_once(self)
            self._vel_publisher.publish(msg)
            dist = abs(y - self._turtle_pose.y)
        msg.linear.y = 0.0

        msg.angular.z = 0.2
        dist = abs(theta%3.14 - self._turtle_pose.theta)
        while dist >= TOL/2:
            rclpy.spin_once(self)
            self._vel_publisher.publish(msg)
            dist = abs(theta%3.14 - self._turtle_pose.theta)
        msg.angular.z = 0.0

def main(args=None):
    rclpy.init(args=args)
    minimal_publisher = TurtleMover()

    while (input("Deseja mudar a tartaruga de lugar? [s/n]")) == 's':
        x_position = input("Digite a posição no eixo x: ")
        y_position = input("Digite a posição no eixo y: ")
        theta_position = input("Digite a angulação da tartaruga: ")
        minimal_publisher.set_position(float(x_position), float(y_position), float(theta_position))
    #rclpy.spin(minimal_publisher)

    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
