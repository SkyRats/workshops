import cv2

# 0 gray scale
# 1 remove transparency
# -1 normal color
img = cv2.imread('images/auau.jpg', 1 )

#double the size
img = cv2.resize(img , (0,0) , fx = 2 , fy= 2)
img = cv2.rotate(img  , cv2.cv2.ROTATE_90_CLOCKWISE)

cv2.imwrite("images/new_auau.jpg" , img)

cv2.imshow("Image" , img)


cv2.waitKey(0)
cv2.destroyAllWindows()
