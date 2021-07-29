//
// Created by Elyas EL IDRISSI on 06/03/2021.
//

#ifndef INFINITECONQUEST_MANAGER_H
#define INFINITECONQUEST_MANAGER_H

#include "Library/hashmap.h"
#include "Sprite/Texture.h"
#include "Text/Font.h"

template <class Resource> class Manager
{

public:
	
	virtual void init() = 0;
	
	void add(const std::string &resourceId, const Resource &resource);
	Resource &get(const std::string &resourceId);
	
	virtual void setDefault() = 0;
	
protected:
	
	static inline std::string ERROR_RESOURCE_NAME = "<error>";
	
	hashmap::unordered_map<std::string, Resource> resources;
};

template<class Resource>
void Manager<Resource>::add(const std::string &resourceId, const Resource &resource)
{
	resources.insert({resourceId, resource});
}

template<class Resource>
Resource &Manager<Resource>::get(const std::string &resourceId)
{
	return (resources.contains(resourceId)) ? resources.at(resourceId) : resources.at(ERROR_RESOURCE_NAME);
}

#endif //INFINITECONQUEST_MANAGER_H
