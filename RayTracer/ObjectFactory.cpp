#include "ObjectFactory.h"
#include "ObjectMaker.h"

ObjectFactory& ObjectFactory::instance()
{
	static ObjectFactory objectFactory_instance;
	return objectFactory_instance;
}

void ObjectFactory::registerMaker(const std::string& key, IObjectMaker* maker)
{
	if (m_makers.find(key) != m_makers.end())
	{
		throw new std::exception("Multiple makers for given key!");
	}
	m_makers[key] = maker;
}

ObjBase* ObjectFactory::make(const nlohmann::json& dict) const
{
	std::string key = dict["type"];
	auto it = m_makers.find(key);
	if (it == m_makers.end())
	{
		throw new std::exception("Unrecognized object type!");
	}
	return it->second->make(dict["data"]);
}