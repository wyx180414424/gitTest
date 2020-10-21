#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat image_1;
	cv::Mat out1,out2,out3,out4;
	cv::Mat srcMat = imread("E:/图片/keda.jpg",0);
	//等待用户按键
	threshold(srcMat, image_1, 100, 255, THRESH_OTSU);
	imshow("二值化效果图", image_1);
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(image_1, out1, element);
	dilate(image_1, out2, element);
	morphologyEx(image_1, out3, MORPH_OPEN, element);
	morphologyEx(image_1, out4, MORPH_CLOSE, element);
	imshow("腐蚀效果图", out1);
	imshow("膨胀效果图", out2);
	imshow("开运算效果图", out3);
	imshow("闭运算效果图", out4);
	waitKey(0);
	return 0;
}