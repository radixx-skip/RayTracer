#pragma once

#include <json.hpp>
#include <Eigen\Core>

using json = nlohmann::json;

Eigen::Vector3d json_array2eigen(const json& json_array)
{
	return Eigen::Vector3d(json_array[0], json_array[1], json_array[2]);
}