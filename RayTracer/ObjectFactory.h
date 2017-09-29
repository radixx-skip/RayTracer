#pragma once

#include <string>
#include <map>
#include <json.hpp>

#include "ObjBase.h"

class IObjectMaker;

class ObjectFactory
{
	ObjectFactory() {}

	ObjectFactory(ObjectFactory const&);
	void operator=(ObjectFactory const&);


	std::map<std::string, IObjectMaker*> m_makers;
public:
	static ObjectFactory& instance();

	void registerMaker(const std::string& key, IObjectMaker* maker);
	ObjBase* make(const nlohmann::json& dict) const;
};