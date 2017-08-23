#include "Ray.h"

Ray::Ray(Eigen::Vector3d position, Eigen::Vector3d direction)
	: m_position(position), m_direction(direction.normalized()) {
}