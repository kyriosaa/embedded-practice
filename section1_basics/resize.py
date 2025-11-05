import cv2 as cv

def rescaleFrame(frame, scale=0.75):
    # images, videos, live video
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

def changeRes(livefeed, width, height):
    # live video only
    livefeed.set(3, width)
    livefeed.set(4, height)

# RESCALE IMAGE (using rescaleFrame)
img = cv.imread('./resources/photos/cat.jpg')
resized_img = rescaleFrame(img, scale=0.5)
cv.imshow('Cat Img', img)
cv.imshow('Cat Img Resized', resized_img)

# RESCALE VIDEO 1 (using rescaleFrame)
# capture = cv.VideoCapture(0) # 0 for webcam
capture = cv.VideoCapture('./resources/videos/dog.mp4')
while True:
    isTrue, frame = capture.read()
    frame_resized = rescaleFrame(frame, scale=0.75)

    cv.imshow('Dog Vid', frame)
    cv.imshow('Dog Vid Resized', frame_resized)

    if cv.waitKey(20) & 0xFF==ord('d'):
        break

# RESCALE VIDEO 2 (using changeRes)
camcap = cv.VideoCapture(0)
changeRes(camcap, 1920, 1080)
while True:
    isTrue, camframe = camcap.read()

    cv.imshow('Webcam', camframe)

    if cv.waitKey(20) & 0xFF==ord('f'):
        break


capture.release()
cv.destroyAllWindows