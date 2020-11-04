#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//读取本地的一张图片便显示出来
	//imread后面的文件路径可以根据自己的实际路径修改。
	Mat out;
	Mat img = imread("E:/图片/英雄.jpg");
	Canny(img, out, 150, 100, 3);
	imshow("test", out);
	//等待用户按键
	waitKey(0);
	return 0;
}