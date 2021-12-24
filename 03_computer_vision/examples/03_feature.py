import numpy as np
import cv2 as cv
from matplotlib import pyplot as plt

img = cv.imread('images/eagle.jpg',0)
img = cv.GaussianBlur(img, (3, 3), 0)

# Initiate ORB detector
orb = cv.ORB_create()
# find the keypoints with ORB
kp = orb.detect(img,None)
# compute the descriptors with ORB
kp, des = orb.compute(img, kp)
# draw only keypoints location,not size and orientation
img2 = cv.drawKeypoints(img, kp, None, color=(0,255,0), flags=0)
cv.imshow('Features', img2)

k = cv.waitKey(0)

if k == ord("s"):
    cv.imwrite("images/eaglefeatures.jpg", img2)
    cv.destroyAllWindows()
