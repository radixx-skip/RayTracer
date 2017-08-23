#pragma once

#include <vector>
#include <Eigen\Core>

#include "ObjBase.h"
#include "Ray.h"

class World
{
	std::vector<ObjBase *> m_objectList;
	World() {}
public:
	static World& instance();

	void add(ObjBase *obj) { m_objectList.push_back(obj); }
	Eigen::Vector3d trace(const Ray& ray);
};