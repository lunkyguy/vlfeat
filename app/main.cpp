#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include "img_matched.h"

bool img_feat(cv::Mat, float, 
	std::vector<VlSiftKeypoint> &, std::vector<std::vector<float>> &, 
	double peak = 0.0, double edge = 10.0);

int main(int argc, char* argv[])
{


	float scale_coef = 0.3;

	cv::Mat src_img = cv::imread("1.jpg");
	std::vector<VlSiftKeypoint> out_fs;
	std::vector<std::vector<float>> out_ds;

	if (!img_feat(src_img, scale_coef, out_fs, out_ds))
		return -1;

	return 0;
}


bool img_feat(cv::Mat src_img, float scale_coef,
	std::vector<VlSiftKeypoint> &out_fs,
	std::vector<std::vector<float>> &out_ds,
	double peak, double edge)
{
	if (src_img.empty()) return false;

	cv::Mat gray_img;
	cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

	cv::Mat f_img;
	gray_img.convertTo(f_img, CV_32F);
	int src_img_w = f_img.cols;
	int src_img_h = f_img.rows;

	int scale_img_w = src_img_w * scale_coef;
	int scale_img_h = src_img_h * scale_coef;
	resize(f_img, f_img, cv::Size(scale_img_w, scale_img_h));
	vl_sift_pix * scale_img_data = (vl_sift_pix *)f_img.data;

	return sift_extract(scale_img_data, scale_img_w, scale_img_h,
		out_fs, out_ds, peak, edge);
}
