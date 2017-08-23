#include "Camera.h"
#include "World.h"
#include "Ray.h"

#include <iostream>

Camera::Camera(int width, int height, double f) 
: m_width(width), m_height(height)
{
	m_imager = cimg_library::CImg<float>(m_width, m_height, 1, 3, 0);

	m_cameraMatrix << f, 0, (width - 1) / 2.0, 0, f, (height - 1) / 2.0, 0, 0, 1;
	m_cameraMatrixInv = m_cameraMatrix.inverse();
}

void Camera::render()
{
	World& world = World::instance();
	Eigen::Vector3d position(0, 0, 0);

	for (int i = 0; i < m_width; i++)
	{
		for (int j = 0; j < m_height; j++)
		{
			Ray ray(position, m_cameraMatrixInv*Eigen::Vector3d(i, j, 1.0));
			//std::cout << "Pixel: " << Eigen::Vector3d(i, j, 1.0) << std::endl;
			//std::cout << "Ray: " << ray.dir() << std::endl;
			Eigen::Vector3d color = world.trace(ray);
			for (int k = 0; k < 3; k++)
			{
				m_imager(i, j, k) = (float)color(k);
			}
		}
	}
}

void Camera::display(const char* title)
{
	m_imager.display(title, false);
}

void Camera::display(cimg_library::CImgDisplay& disp)
{
	disp = m_imager;
}