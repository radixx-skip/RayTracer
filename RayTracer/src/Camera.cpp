#include "Camera.h"

Camera::Camera(int width, int height) 
: m_width(width), m_height(height) {
	m_imager = cimg_library::CImg<float>(m_width, m_height, 1, 3, 0);
}

void Camera::render() {
	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			m_imager(i, j, 1) = (float)i / m_width;
			m_imager(i, j, 2) = (float)j / m_height;
		}
	}
}

void Camera::display(const char* title) {
	m_imager.display(title, false);
}

void Camera::display(cimg_library::CImgDisplay& disp) {
	disp = m_imager;
}