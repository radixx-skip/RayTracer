#pragma once

#include <CImg.h>
#include <Eigen\Dense>

class Camera
{
	int m_width;
	int m_height;
	Eigen::Matrix3d m_cameraMatrix;
	Eigen::Matrix3d m_cameraMatrixInv;

	cimg_library::CImg<float> m_imager;
public:
	Camera(int width, int height, double f);
	void render();
	void display(const char* title = "");
	void display(cimg_library::CImgDisplay& disp);
};