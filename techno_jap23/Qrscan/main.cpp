#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/objdetect/graphical_code_detector.hpp>


using namespace std;
using namespace cv;

string path, Data;
Mat img, points, rectimg;



void boundQr( Mat &img, Mat &points)
{
	int n = points.rows;

	for (int i = 0; i < n; i++)
	{
		line(img, Point2i(points.at<float>(i, 0), points.at<float>(i, 1)), Point2i(points.at<float>((i + 1) % n, 0), points.at<float>((i + 1) % n, 1)), Scalar(255, 0, 0), 3);
	}

	imshow("result", img);
}

int main()
{
	path = "E:\\AUV\\techno_jap23\\Resources\\Qr.png";
	img = imread(path);

	if (img.empty())
	{
		cout << "Image could not be read" << endl;
	}

	QRCodeDetector QR = QRCodeDetector::QRCodeDetector();

	Data = QR.detectAndDecodeCurved(img, points, rectimg);
	//Data = QR.detect(img, points);

	cout << points << endl;
	cout << rectimg << endl;

	if (Data.length() > 0)
	{

		boundQr(img, points);
		cout << Data << endl;

		rectimg.convertTo(rectimg, CV_8UC3);

		imshow("Qr", rectimg);
		waitKey(0);
	}

	


	/*VideoCapture cap(0);
	
	while (true)
	{
		cap.read(img);

		if (img.empty())
		{
			cout << "!!!!!Image not loaded!!!!!" << endl;
		}

		Mat points, rectimg;

		QRCodeDetector qr = QRCodeDetector::QRCodeDetector();

		Data = qr.detectAndDecode(img, points, rectimg);

		if (Data.length() > 0)
		{
			cout << Data << endl;
		}

		imshow("Qr", img);
		waitKey(1);
	}*/

	return 0;
}