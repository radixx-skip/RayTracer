#include "World.h"
#include "ObjectFactory.h"

#include <json.hpp>
#include <fstream>
#include <string>

World& World::instance()
{
	static World world_instance;
	return world_instance;
}

World::~World()
{
	for each (ObjBase* obj in m_objectList)
	{
		delete obj;
	}
}

void World::add(const char* file)
{
	std::ifstream f(file);
	nlohmann::json j;
	f >> j;

	for (int i = 0; i < j.size(); i++)
	{
		nlohmann::json dict = j[i];
		add(ObjectFactory::instance().make(dict));
	}
}

Eigen::Vector3d World::trace(const Ray& ray)
{
	if (!m_objectList.empty())
	{
		double min_dist = HUGE_VAL;
		ObjBase *min_obj = nullptr;
		for each (ObjBase *curr_obj in m_objectList)
		{
			double curr_dist = curr_obj->distance(ray);
			if (curr_dist < min_dist)
			{
				min_dist = curr_dist;
				min_obj = curr_obj;
			}
		}

		if (min_obj)
		{
			return(min_obj->intersect(ray));
		}
	}

	return Eigen::Vector3d(0.0, 0.0, 0.0);
}