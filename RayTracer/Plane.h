#pragma once

#include "ObjBase.h"

class Plane :
	public ObjBase
{
	Eigen::Vector3d m_point;
	Eigen::Vector3d m_normal;
	Eigen::Vector3d m_colour;

public:
	Plane(const Eigen::Vector3d& point, const Eigen::Vector3d& normal, const Eigen::Vector3d& colour);
	~Plane();

	virtual double distance(const Ray& ray) const;
	virtual Eigen::Vector3d intersect(const Ray& ray) const;
};

