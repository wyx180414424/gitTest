#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	//��ȡ���ص�һ��ͼƬ����ʾ����
	//imread������ļ�·�����Ը����Լ���ʵ��·���޸ġ�
	Mat out;
	Mat img = imread("E:/ͼƬ/Ӣ��.jpg");
	Canny(img, out, 150, 100, 3);
	imshow("test", out);
	//�ȴ��û�����
	waitKey(0);
	return 0;
}