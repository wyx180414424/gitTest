#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int count;
	cv::Mat image_1, out1, out2, out3;
	cv::Mat labels, states, centroids;
	cv::Mat srcMat = imread("E:/图片/原点.jpg", 0);
	//等待用户按键
	threshold(srcMat, image_1, 100, 255, THRESH_BINARY);
	Mat element1 = getStructuringElement(MORPH_RECT, Size(25, 25));
	Mat element2 = getStructuringElement(MORPH_RECT, Size(25, 25));
	dilate(image_1, out1, element1);
	erode(out1, out2, element2);
	adaptiveThreshold(out2, out3, 255, ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY_INV, 29, 10);
	imshow("先膨胀后腐蚀", out2);
	imshow("两次二值化", out3);
	count = connectedComponentsWithStats(out3, labels, states, centroids, 8, CV_32S);
	cout << count-1;
	waitKey(0);
	return 0;
}
