# https://docs.opencv.org/3.4/d5/dc4/tutorial_video_input_psnr_ssim.html

import cv2 as cv

cap = cv.VideoCapture(0)
frame_ind = 0

while(True):
    ret, frame = cap.read()

    cv.imshow('Output', frame)

    if cv.waitKey(1) & 0xFF == ord('s'):
    	cv.imwrite(f"capture/frame_{frame_ind}.jpg", frame)
    	frame_ind += 1 
 
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
 
cap.release()
cv.destroyAllWindows()