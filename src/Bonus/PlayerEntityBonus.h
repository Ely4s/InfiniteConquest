//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYBONUS_H
#define INFINITECONQUEST_PLAYERENTITYBONUS_H

#include "EntityBonus.h"
#include "Entity/PlayerEntity.h"
#include "Utils/Instanceof.h"

class PlayerEntityBonus : public EntityBonus
{

public:
	
	virtual bool apply(Entity * target)
	{
		return instanceof<PlayerEntity>(target);
	}

protected:
	
	PlayerEntityBonus(float value, const std::string &label) : EntityBonus(value, label){}

};

#endif //INFINITECONQUEST_PLAYERENTITYBONUS_H
