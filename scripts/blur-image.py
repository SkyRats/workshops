import numpy as np
import cv2 
from matplotlib import pyplot as plt
img = cv2.imread('./images/auau.jpg',-1)


blur_size = 5 #can't be zero
blurredFrame = cv2.blur(img, (blur_size, blur_size))

plt.subplot(121),plt.imshow(img,cmap = 'gray')
plt.title('Original Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(blurredFrame,cmap = 'gray')
plt.title('Blurred Image'), plt.xticks([]), plt.yticks([])
plt.show()
