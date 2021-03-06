#pragma once

#include <Eigen\Core>

class Ray {
	Eigen::Vector3d m_position;
	Eigen::Vector3d m_direction;

public:
	Ray(const Eigen::Vector3d &position, const Eigen::Vector3d &direction);

	Eigen::Vector3d pos() const { return m_position; }
	Eigen::Vector3d dir() const { return m_direction; }

	Ray project(double distance) const;
};