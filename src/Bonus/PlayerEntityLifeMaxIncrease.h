//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYLIFEMAXINCREASE_H
#define INFINITECONQUEST_PLAYERENTITYLIFEMAXINCREASE_H

#include "PlayerEntityBonus.h"

#include <math.h>

class PlayerEntityLifeMaxIncrease : public PlayerEntityBonus
{

public:
	
	PlayerEntityLifeMaxIncrease() : PlayerEntityBonus(1.2f, "+ Vie Maximum"){};
	
	bool apply(Entity * target) override
	{
		if (PlayerEntityBonus::apply(target))
		{
			PlayerEntity * player = (PlayerEntity*)target;
			player->setLifePointMax((int) round((float)player->getLifePointMax() * getValue()));
			player->setLifePoint((int) round((float)player->getLifePoint() * getValue()));
			
			return true;
		}
		else
		{
			return false;
		}
	}
};


#endif //INFINITECONQUEST_PLAYERENTITYLIFEMAXINCREASE_H
