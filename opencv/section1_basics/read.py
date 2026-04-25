import cv2 as cv

# READ IMAGE
# img = cv.imread('./resources/photos/cat.jpg')
# img = cv.imread('./resources/photos/cat_large.jpg')
# cv.imshow('Cat Pic', img)

# READ VIDEO
# capture = cv.VideoCapture(0) # 0 for webcam
capture = cv.VideoCapture('./resources/videos/dog.mp4')
while True:
    isTrue, frame = capture.read()
    cv.imshow('Dog Vid', frame)

    if cv.waitKey(20) & 0xFF==ord('d'):
        break

capture.release()
cv.destroyAllWindows

# -215:Assertion failed
# ^ incorrect path or video frame end