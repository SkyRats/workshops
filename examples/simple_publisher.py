import rospy
# from somewhere.msg import TipoDeMsg

rospy.init_node("nome_do_node")
rate = rospy.Rate(60)
pub = rospy.Publisher("nome_do_topico", TipoDeMsg, queue_size=1)

def main():
    msg = TipoDeMsg(param1, param2, ..., paramN)
    pub.publish()
    rate.sleep()