import numpy 
import cv2

cap = cv2.VideoCapture(0)

while True:
    sucess , frame = cap.read()
    width = int(cap.get(3))
    height = int(cap.get(4))


    image = numpy.zeros(frame.shape , numpy.uint8)
    smaller_frame = cv2.resize(frame, (0,0) , fx = 0.5 , fy = 0.5)

    image[:height//2 , :width//2] = smaller_frame
    image[:height//2 , width//2:] = cv2.flip(smaller_frame , 1)
    image[height//2: , :width//2] = smaller_frame
    image[height//2: , width//2:] = cv2.flip(smaller_frame , 1)

    cv2.imshow("frame" , image)

    if cv2.waitKey(1) == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
