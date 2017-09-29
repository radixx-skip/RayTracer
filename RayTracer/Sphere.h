#pragma once

#include <json.hpp>

#include "ObjBase.h"

class Sphere : public ObjBase
{
	Eigen::Vector3d m_point;
	double m_radius;
	Eigen::Vector3d m_colour;

public:
	Sphere(const Eigen::Vector3d& point, double radius, const Eigen::Vector3d& colour);
	Sphere(const nlohmann::json& dict);
	~Sphere();

	virtual double distance(const Ray& ray) const;
	virtual Eigen::Vector3d intersect(const Ray& ray) const;
};

