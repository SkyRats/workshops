import numpy 
import cv2

cap = cv2.VideoCapture(0)

while True:
    sucess , frame = cap.read()
    
    cv2.imshow("frame" , frame)

    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
