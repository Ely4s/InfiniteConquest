//
// Created by Elyas EL IDRISSI on 27/03/2021.
//

#ifndef INFINITECONQUEST_ENTITYBONUS_H
#define INFINITECONQUEST_ENTITYBONUS_H

#include <string>
#include <utility>
#include <iostream>
#include "Entity/Entity.h"

class EntityBonus
{

public:
	
	virtual bool apply(Entity * target) = 0;
	float getValue() const {return VALUE;};
	std::string getLabel() {return LABEL;};
	
	virtual ~EntityBonus() = default;

protected:
	
	EntityBonus(float VALUE, const std::string &LABEL)
	{
		EntityBonus::VALUE = VALUE;
		EntityBonus::LABEL = LABEL;
	};
	
	float VALUE = 0;
	std::string LABEL;
	
};


#endif //INFINITECONQUEST_ENTITYBONUS_H
