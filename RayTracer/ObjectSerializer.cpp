#include "ObjectSerializer.h"
#include "ObjectHeaders.h"
#include <json.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <Eigen\Core>

using json = nlohmann::json;

Eigen::Vector3d json_array2eigen(const json& json_array)
{
	return Eigen::Vector3d(json_array[0], json_array[1], json_array[2]);
}

std::vector<ObjBase*> loadObjects(const char* file)
{
	std::ifstream f(file);
	json j;
	f >> j;

	std::vector<ObjBase*> obj_list;
	for (int i = 0; i < j.size(); i++)
	{
		json j_obj = j[i];
		std::string type = j_obj["type"];
		if (type.compare("Plane") == 0)
		{
			Eigen::Vector3d point = json_array2eigen(j_obj["point"]);
			Eigen::Vector3d normal = json_array2eigen(j_obj["normal"]);
			Eigen::Vector3d colour = json_array2eigen(j_obj["colour"]);
			obj_list.push_back(new Plane(point, normal, colour));
		}
	}
	return obj_list;
}