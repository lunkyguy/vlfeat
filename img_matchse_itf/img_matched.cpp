#include "img_matched.h"

bool sift_extract(vl_sift_pix *img_data, int img_w, int img_h,
	std::vector<VlSiftKeypoint> & fs, std::vector<std::vector<float>> & ds,
	double peak /*= 0.0*/, double edge /*= 10.0*/)
{
	int result = -1;
	VlSiftFilt * vl_sift = nullptr;
	
	vl_sift = vl_sift_new(img_w, img_h, 4, 3, 0);
	if (vl_sift == nullptr) goto _END;

	vl_sift_set_peak_thresh(vl_sift, peak);
	vl_sift_set_edge_thresh(vl_sift, edge);

	result = vl_sift_process_first_octave(vl_sift, img_data);
	if (result != VL_ERR_OK) goto _END;
	do 
	{
		vl_sift_detect(vl_sift);

		VlSiftKeypoint* kpt = vl_sift->keys;

		for (int i = 0; i < vl_sift->nkeys; i++)
		{
			double angles[4] = {0};
			int angle_count = vl_sift_calc_keypoint_orientations(vl_sift, angles, kpt);

			for (int j = 0; j < angle_count; j++)
			{
				const int des_size = 8 * 4 * 4;
				std::vector<float> fbuf;
				fbuf.resize(des_size);
				float *pdes = &*fbuf.begin();
				vl_sift_calc_keypoint_descriptor(vl_sift, pdes, kpt, angles[0]);
				ds.push_back(fbuf);
				fs.push_back(*kpt);
			}

			kpt++;
		}
	} while (vl_sift_process_next_octave(vl_sift) == VL_ERR_OK);

_END:

	if (vl_sift != nullptr)
	{
		vl_sift_delete(vl_sift);
		vl_sift = nullptr;
	}
		
	return (result == VL_ERR_OK ? true : false);
}