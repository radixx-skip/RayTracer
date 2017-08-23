#pragma once

#include <CImg.h>

class Camera {
	int m_width;
	int m_height;

	cimg_library::CImg<float> m_imager;
public:
	Camera(int width, int height);
	void render();
	void display(const char* title = "");
	void display(cimg_library::CImgDisplay& disp);
};