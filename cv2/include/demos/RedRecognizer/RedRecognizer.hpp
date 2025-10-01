#pragma once

#include <opencv2/opencv.hpp>

class RedRecognizer {
public:
	RedRecognizer();
	int run_static(void);
	int run_video();


private:
	cv::VideoCapture captureDevice;
	cv::Point2f find_red(cv::Mat& frame);
};