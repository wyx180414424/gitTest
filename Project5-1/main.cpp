#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps0" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat out1,out2,out3,out4,out5;
		bool rSucess = cap.read(frame);
		medianBlur(frame, out1, 15);
		blur(frame, out2, Size(7, 7));
		GaussianBlur(frame, out3, Size(5, 5), 0, 0);
		Sobel(frame, out4, CV_16S, 1, 0, 7, 1, 1, BORDER_DEFAULT);
		Sobel(frame, out5, CV_16S, 0, 1, 7, 1, 1, BORDER_DEFAULT);
		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			cv::imshow("中值滤波",out1);
			cv::imshow("均值滤波", out2);
			cv::imshow("高斯滤波", out3);
			cv::imshow("x方向", out4);
			cv::imshow("y方向", out5);

		}
		waitKey(30);
	}
	return 0;
}