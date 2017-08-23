#pragma once

#include <Eigen\Core>

#include "Ray.h"

class ObjBase
{
	ObjBase() {}
public:
	~ObjBase() {}

	virtual double distance(const Ray& ray) = 0;
	virtual Eigen::Vector3d intersect(const Ray& ray) = 0;
};

