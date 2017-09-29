#pragma once

#include <string>
#include <json.hpp>

#include "ObjBase.h"
#include "ObjectFactory.h"

#define REGISTER_OBJECT(T) static ObjectMaker<T> maker(#T);

class IObjectMaker
{
public:
	virtual ObjBase* make(const nlohmann::json& dict) const = 0;
};

template<typename T>
class ObjectMaker : IObjectMaker
{
public:
	ObjectMaker(const std::string& key)
	{
		ObjectFactory::instance().registerMaker(key, this);
	}
	ObjBase* make(const nlohmann::json& dict) const
	{
		return new T(dict);
	}
};