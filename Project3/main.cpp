#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("E:/ͼƬ/keda.jpg",0);
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}