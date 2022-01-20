#ifndef IMG_MATCHED_H
#define IMG_MATCHED_H
#include <string>
#include <vector>
#include "sift.h"

bool sift_extract(vl_sift_pix *img_data, int img_w, int img_h, 
	std::vector<VlSiftKeypoint> & fs, std::vector<std::vector<float>> & ds,
	double peak = 0.0, double edge = 10.0);
#endif