//
// Created by Elyas EL IDRISSI on 27/03/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYLIFEREGENERATION_H
#define INFINITECONQUEST_PLAYERENTITYLIFEREGENERATION_H

#include "PlayerEntityBonus.h"

#include <math.h>

class PlayerEntityLifeRegeneration : public PlayerEntityBonus
{

public:
	
	PlayerEntityLifeRegeneration() : PlayerEntityBonus(3, "Regeneration partielle"){};
	
	bool apply(Entity * target) override
	{
		if (PlayerEntityBonus::apply(target))
		{
			PlayerEntity * player = (PlayerEntity*)target;
			player->setLifePoint((int) ceil( (float)player->getLifePoint() + ((float)player->getLifePointMax() / getValue()) ) );
			
			return true;
		}
		else
		{
			return false;
		}
	}
};

#endif //INFINITECONQUEST_PLAYERENTITYLIFEREGENERATION_H
