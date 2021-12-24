import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt

img1 = cv.imread('images/eaglerot.jpg',cv.IMREAD_GRAYSCALE)          # queryImage
img1 = cv.GaussianBlur(img1, (3,3), 0)
img2 = cv.imread('images/rhino_eagle.jpg',cv.IMREAD_GRAYSCALE) # trainImage
img2 = cv.GaussianBlur(img2, (3,3), 0)

# Initiate ORB detector
orb = cv.ORB_create()
# find the keypoints and descriptors with ORB
kp1 = orb.detect(img1,None)
# compute the descriptors with ORB
kp1, des1 = orb.compute(img1, kp1)
# find the keypoints and descriptors with ORB
kp2 = orb.detect(img2,None)
# compute the descriptors with ORB
kp2, des2 = orb.compute(img2, kp2)

#kp2, des2 = orb.detectAndCompute(img2, None)

print (kp1, des1)
print (kp2, des2)

# create BFMatcher object
bf = cv.BFMatcher(cv.NORM_HAMMING, crossCheck=True)
# Match descriptors.
matches = bf.match(des1,des2)
# Sort them in the order of their distance.
matches = sorted(matches, key = lambda x:x.distance)
# Draw first 10 matches.
img3 = cv.drawMatches(img1,kp1,img2,kp2,matches[:10],None,flags=cv.DrawMatchesFlags_NOT_DRAW_SINGLE_POINTS)
plt.imshow(img3),plt.show()