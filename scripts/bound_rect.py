# CODE AVAILABLE AT https://www.pythonpool.com/cv2-boundingrect/

import cv2
 
image = cv2.imread("YOUR_IMG_PATH")
cv2.imshow("image",image)
gray =cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow("Changed",gray)
ret,binary = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
contours,hierarchy = cv2.findContours(binary,cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
print("Number of contours:" + str(len(contours)))
x,y,w,h = cv2.boundingRect(contours[0])
cv2.rectangle(image,(x,y),(x+w,y+h),(255,0,0),3)
cv2.imshow("result",image)
cv2.waitKey(0)
cv2.destroyAllWindows()
