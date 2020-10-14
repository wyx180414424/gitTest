#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	Mat image_1;
	Mat image_2;
	//读取本地的一张图片便显示出来
	//imread后面的文件路径可以根据自己的实际路径修改。
	Mat srcMat = imread("E:/图片/keda.jpg",0);
	//等待用户按键
	threshold(srcMat, image_1, 100, 255, THRESH_OTSU);
	adaptiveThreshold(srcMat, image_2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 29, 10);
	imshow("src", srcMat);
	imshow("大津", image_1);
	imshow("自适应", image_2);
	waitKey(0);
	return 0;
}