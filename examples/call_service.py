import rospy
# from somehwere.srv import TipoDeSrv

service = rospy.ServiceProxy("service", TipoDeSrv)

def main():
  service(arg1, arg2, ..., argN)