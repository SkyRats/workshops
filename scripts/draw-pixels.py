import cv2

img = cv2.imread('images/auau.jpg', -1)

part = img[10:150 , 60:180]

img[10:150 , 155:275] = part


cv2.imshow("Image" , img)
cv2.waitKey(0)
cv2.destroyAllWindows()
