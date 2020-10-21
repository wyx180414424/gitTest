#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int count,i,j=0;
	cv::Mat image_1,dispMat;
	cv::Mat labels,states,centroids;
	cv::Rect rect;
	cv::Mat srcMat = imread("E:/Í¼Æ¬/Ó²±Ò.jpg", 0);
	//µÈ´ýÓÃ»§°´¼ü
	threshold(srcMat, image_1, 100, 255, THRESH_BINARY);
	count=connectedComponentsWithStats(image_1, labels, states, centroids,8, CV_32S);
	for (i =1; i <count; i++)
	{
		    j = 0;
			rect.x= states.at<int>(i, j);
			j++;
			rect.y= states.at<int>(i, j);
			j++;
			rect.width= states.at<int>(i, j);
			j++;
			rect.height = states.at<int>(i, j);
		    rectangle(image_1, rect, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	cout << count-1;
	imshow("Ó²±Ò",image_1);
	waitKey(0);
	return 0;
}