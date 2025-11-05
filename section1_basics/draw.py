import cv2 as cv
import numpy as np

blank = np.zeros((500, 500, 3), dtype = 'uint8')    # (500, 500, 3) - (width, height, color channels)
cv.imshow('Blank', blank)

# 1. Paint the entire image a certain color
blank[:] = 0, 255, 0
cv.imshow('Green', blank)
blank[:] = 0, 0, 255
cv.imshow('Red', blank)
blank[:] = 0, 0, 0

# 2. Paint a portion of an image a certain color
blank[200:300, 300:400] = 255, 0, 0
cv.imshow('Blue', blank)
blank[:] = 0, 0, 0

# 3. Draw a rectangle
cv.rectangle(blank, (0,0), (250,500), (0,255,0), thickness=-1) # thickness -1 for fill
cv.imshow('Rectangle', blank)
blank[:] = 0, 0, 0 

# 4. Draw a circle
cv.circle(blank, (250,250), 40, (0,0,255), thickness=3)
cv.imshow('Circle', blank)
blank[:] = 0, 0, 0

# 5. Draw a line
cv.line(blank, (0,0), (250,250), (255,0,0), thickness=2)
cv.imshow('Line', blank)
blank[:] = 0, 0, 0

# 6. Write text
cv.putText(blank, 'Hello', (225,255), cv.FONT_HERSHEY_TRIPLEX, 1.0, (0,255,0), thickness=2)
cv.imshow('Text', blank)
blank[:] = 0, 0, 0

cv.waitKey(0)