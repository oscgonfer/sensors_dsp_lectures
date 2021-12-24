# Tutorial from here: 
# https://docs.opencv.org/3.4/d2/d2c/tutorial_sobel_derivatives.html

import sys
import cv2 as cv
import numpy as np
window_name = ('Sobel Demo - Simple Edge Detector')
scale = 0.5 
delta = 0
ddepth = cv.CV_16S

src = cv.imread('images/eagle.jpg', cv.IMREAD_COLOR)

# Reduce noise
src = cv.GaussianBlur(src, (3, 3), 0)

# BW
gray = cv.cvtColor(src, cv.COLOR_BGR2GRAY)

grad_x = cv.Sobel(gray, ddepth, 1, 0, ksize=3, scale=scale, delta=delta, borderType=cv.BORDER_DEFAULT)
# Gradient-Y
# grad_y = cv.Scharr(gray,ddepth,0,1)
grad_y = cv.Sobel(gray, ddepth, 0, 1, ksize=3, scale=scale, delta=delta, borderType=cv.BORDER_DEFAULT)

abs_grad_x = cv.convertScaleAbs(grad_x)
abs_grad_y = cv.convertScaleAbs(grad_y)

grad = cv.addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0)

print (grad.shape)
print (grad)
np.savetxt("sobel.txt", grad.astype(int), newline="\n")
cv.imshow(window_name, grad)

k = cv.waitKey(0)

if k == ord("q"):
    cv.imwrite("images/eaglesobel.jpg", grad)
    cv.destroyAllWindows()