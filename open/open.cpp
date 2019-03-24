#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;


int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("1.jpg");
	namedWindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);//传入输入图片并显示
	
	Mat k_la = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	Mat k_x = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	Mat k_y = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	Mat la, x, y;
	namedWindow("la", CV_WINDOW_AUTOSIZE);
	namedWindow("x", CV_WINDOW_AUTOSIZE);
	namedWindow("y", CV_WINDOW_AUTOSIZE);
	filter2D(src, la, -1, k_la, Point(-1, -1), 0.0);//源，输出，算子，锚点
	filter2D(src, x, -1, k_x, Point(-1, -1), 0.0);//源，输出，算子，锚点
	filter2D(src, y, -1, k_y, Point(-1, -1), 0.0);//源，输出，算子，锚点
	imshow("la", la);
	imshow("x", x);
	imshow("y", y);
	waitKey(0);
	return 0;
}	
