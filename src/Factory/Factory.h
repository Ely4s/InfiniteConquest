//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#ifndef INFINITECONQUEST_FACTORY_H
#define INFINITECONQUEST_FACTORY_H

#include "Library/hashmap.h"

typedef struct
{
	std::string id;
	std::string name;
	
} Ids;

template <class Pattern> class Factory
{

public:
	
	Factory() = default;
	
	virtual void init() = 0;
	void add(const std::string &patternId, const Pattern &pattern);
	const Pattern &get(const std::string &patternId);
	Pattern getCopy(const std::string &patternId);

protected:
	
	hashmap::unordered_map<std::string, Pattern> patterns;
	
};

template <class Pattern>
void Factory<Pattern>::add(const std::string &patternId, const Pattern &pattern)
{
	patterns.insert({patternId, pattern});
};

template <class Pattern>
const Pattern &Factory<Pattern>::get(const std::string &patternId)
{
	return patterns.at(patternId);
};

template <class Pattern>
Pattern Factory<Pattern>::getCopy(const std::string &patternId)
{
	return patterns.at(patternId);
};

#endif //INFINITECONQUEST_FACTORY_H
