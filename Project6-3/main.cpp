#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	Mat out;
	Mat img = cv::imread("E:/Í¼Æ¬/Ó¢ÐÛ.jpg");
	if (img.empty()) return -1;
	
	const cv::Point2f src_pt[] = {
        cv::Point2f(200, 200),
	    cv::Point2f(250, 200),
		cv::Point2f(200, 100)};
	const cv::Point2f dst_pt[] = {
		cv::Point2f(300, 100),
		cv::Point2f(300, 50),
		cv::Point2f(200, 100)};
	const cv::Mat  affine_matrix = cv::getAffineTransform(src_pt,dst_pt);

	cv::warpAffine(img, out, affine_matrix, img.size());

	cv::imshow("src", img);
	cv::imshow("dst", out);
	cv::waitKey(0);
	return 0;
}