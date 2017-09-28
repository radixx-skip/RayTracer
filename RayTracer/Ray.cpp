#include "Ray.h"

Ray::Ray(const Eigen::Vector3d &position, const Eigen::Vector3d &direction)
	: m_position(position), m_direction(direction.normalized()) {
}

Ray Ray::project(double distance) const
{
	return Ray(m_position + distance*m_direction, m_direction);
}