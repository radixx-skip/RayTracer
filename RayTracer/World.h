#pragma once

#include <vector>
#include <Eigen\Core>

#include "ObjBase.h"
#include "Ray.h"

class World
{
	std::vector<ObjBase *> m_objectList;
	World() {}

	World(World const&);
	void operator=(World const&);
public:
	static World& instance();
	~World();

	void add(ObjBase* obj) { m_objectList.push_back(obj); }
	void add(const char* file);
	Eigen::Vector3d trace(const Ray& ray);
};