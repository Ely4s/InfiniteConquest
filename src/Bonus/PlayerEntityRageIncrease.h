//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYRAGEINCREASE_H
#define INFINITECONQUEST_PLAYERENTITYRAGEINCREASE_H

#include "PlayerEntityBonus.h"

#include <math.h>

class PlayerEntityRageIncrease : public PlayerEntityBonus
{
	
public:
	
	PlayerEntityRageIncrease() : PlayerEntityBonus(1.2f, "+ Degats de Rage"){};
	
	virtual bool apply(Entity * target) override
	{
		
		if (PlayerEntityBonus::apply(target))
		{
			PlayerEntity * player = dynamic_cast<PlayerEntity*>(target);
			player->setRageDamage((int) round((float)player->getRageDamage() * getValue()));
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
};


#endif //INFINITECONQUEST_PLAYERENTITYRAGEINCREASE_H
