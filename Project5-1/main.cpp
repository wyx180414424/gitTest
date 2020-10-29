#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
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
			std::cout << "���ܴ���Ƶ�ļ��ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			cv::imshow("��ֵ�˲�",out1);
			cv::imshow("��ֵ�˲�", out2);
			cv::imshow("��˹�˲�", out3);
			cv::imshow("x����", out4);
			cv::imshow("y����", out5);

		}
		waitKey(30);
	}
	return 0;
}