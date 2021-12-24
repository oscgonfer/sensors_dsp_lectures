'''
Open an image and make it black and white
Then save it
'''

import cv2 as cv
import sys

img = cv.imread("images/eagle.jpg")

if img is None:
    sys.exit("Could not read the image.")

print (img)

cv.imshow("Eagle", img)

k = cv.waitKey(0)
if k == ord("s"):
    imgbw = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    cv.imwrite("images/eaglebw.jpg", imgbw)
    cv.destroyAllWindows()
