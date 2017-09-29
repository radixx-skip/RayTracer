#pragma once

#include <Eigen\Core>
#include "Ray.h"

class ObjBase
{
public:
	ObjBase() {}
	~ObjBase() {}

	virtual double distance(const Ray& ray) const = 0;
	virtual Eigen::Vector3d intersect(const Ray& ray) const = 0;
};

