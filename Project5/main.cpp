#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("E:/ͼƬ/keda.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	deepMat = srcMat;
	srcMat.copyTo(shallowMat);
	uchar threshold = 100;
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold) average = 255;
			else average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;

		}
	}
	imshow("src", srcMat);
	imshow("deep", deepMat);
	imshow("shollow", shallowMat);
	waitKey(0);
	return 0;
}