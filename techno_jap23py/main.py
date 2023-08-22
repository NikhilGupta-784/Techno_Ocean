import cv2


def boundqr(img, points):
    n = len(points)
    for i in range(n):
        x1 = int(points[i][0])
        y1 = int(points[i][1])
        x2 = int(points[(i+1) % n][0])
        y2 = int(points[(i+1) % n][1])

        cv2.line(img, (x1,y1), (x2, y2), (255, 0, 255), 3)
    cv2.imshow("QR", img)


def measurqr(points):
    for i in range(2):
        if i == 0:
            x1 = int(points[i][0])
            x2 = int(points[(i + 1) % 2][0])
        elif i == 1:
            y1 = int(points[i][1])
            y2 = int(points[(i + 1) % 3][1])

    print(" Length of QR Code is in pixel: ", x2-x1)
    print(" Width of QR Code is in pixel : ", y2-y1)




#######WEBCAM QR#######

input = cv2.VideoCapture(0)
while True:
    Success,img = input.read()
    cv2.imshow("QR", img)
    cv2.waitKey(1)

    #print(d_points, '\n')
    qr = cv2.QRCodeDetector()
    data, points, rectimg = qr.detectAndDecode(img)



    if len(data) > 0:
        d_points = points.reshape((4, 2)).copy()
        measurqr(d_points)
        boundqr(img, d_points)
        print(data)

        cv2.imshow("QR", img)
        cv2.waitKey(0)


########IMAGE QR######

'''img = cv2.imread('E:\\AUV\\techno_jap23py\\Resources\\Qr.png')

qr = cv2.QRCodeDetector()
data, points, rectimg = qr.detectAndDecode(img)

d_points = points.reshape((4,2)).copy()

print(d_points)

measurqr(d_points)

if len(data) > 0:
    boundqr(img, d_points)
    cv2.imshow("QR", img)
    print(data)
    cv2.waitKey(0)'''



