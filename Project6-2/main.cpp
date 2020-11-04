#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	Mat out;
	Mat img =cv::imread("E:/Í¼Æ¬/Ó¢ÐÛ.jpg");
	if (img.empty()) return -1;
	float angle = -10.0, scale = 1;
	cv::Point2f center(img.cols*0.5, img.rows*0.5);
	const cv::Mat  affine_matrix = cv::getRotationMatrix2D(center, angle, scale);

	cv::warpAffine(img, out, affine_matrix, img.size());

	cv::imshow("src", img);
	cv::imshow("dst", out);
	cv::waitKey(0);
	return 0;
}