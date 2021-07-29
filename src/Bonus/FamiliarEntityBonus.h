//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_FAMILIARENTITYBONUS_H
#define INFINITECONQUEST_FAMILIARENTITYBONUS_H

#include "EntityBonus.h"
#include "Entity/FamiliarEntity.h"

class FamiliarEntityBonus : public EntityBonus
{

public:
	
	virtual bool apply(Entity * target) override
	{
		return instanceof<FamiliarEntity>(target);
	}

protected:
	
	FamiliarEntityBonus(float value, const std::string &label) : EntityBonus(value, label){}
};

#endif //INFINITECONQUEST_FAMILIARENTITYBONUS_H
