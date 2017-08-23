#include "World.h"

World& World::instance()
{
	static World world_instance = World();
	return world_instance;
}

Eigen::Vector3d World::trace(const Ray& ray)
{
	return ray.dir().cwiseAbs();
}