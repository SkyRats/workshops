import rospy
# from somewhere.msg import TipoDeMsg

def callback_func(data):
  print(data)

rospy.init_node("nome_do_node")
rate = rospy.Rate(60)
sub = rospy.Subscriber("nome_do_topico", TipoDeMsg, callback_func)


def main():
  rospy.spin()
