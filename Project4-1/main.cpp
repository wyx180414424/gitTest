#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat image_1;
	cv::Mat out1,out2,out3,out4;
	cv::Mat srcMat = imread("E:/ͼƬ/keda.jpg",0);
	//�ȴ��û�����
	threshold(srcMat, image_1, 100, 255, THRESH_OTSU);
	imshow("��ֵ��Ч��ͼ", image_1);
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(image_1, out1, element);
	dilate(image_1, out2, element);
	morphologyEx(image_1, out3, MORPH_OPEN, element);
	morphologyEx(image_1, out4, MORPH_CLOSE, element);
	imshow("��ʴЧ��ͼ", out1);
	imshow("����Ч��ͼ", out2);
	imshow("������Ч��ͼ", out3);
	imshow("������Ч��ͼ", out4);
	waitKey(0);
	return 0;
}