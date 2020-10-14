#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	Mat image_1;
	Mat image_2;
	//��ȡ���ص�һ��ͼƬ����ʾ����
	//imread������ļ�·�����Ը����Լ���ʵ��·���޸ġ�
	Mat srcMat = imread("E:/ͼƬ/keda.jpg",0);
	//�ȴ��û�����
	threshold(srcMat, image_1, 100, 255, THRESH_OTSU);
	adaptiveThreshold(srcMat, image_2, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 29, 10);
	imshow("src", srcMat);
	imshow("���", image_1);
	imshow("����Ӧ", image_2);
	waitKey(0);
	return 0;
}