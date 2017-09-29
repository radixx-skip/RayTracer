#pragma once

#include <json.hpp>
#include <Eigen\Core>

inline Eigen::Vector3d json_array2eigen(const nlohmann::json& json_array)
{
	return Eigen::Vector3d(json_array[0], json_array[1], json_array[2]);
}