//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYATTACKINCREASE_H
#define INFINITECONQUEST_PLAYERENTITYATTACKINCREASE_H

#include "PlayerEntityBonus.h"

#include <math.h>

class PlayerEntityAttackIncrease : public PlayerEntityBonus
{

public:
	
	PlayerEntityAttackIncrease() : PlayerEntityBonus(1.2f, "+ Degats Personnage"){};
	
	bool apply(Entity * target) override
	{
		if (PlayerEntityBonus::apply(target))
		{
			PlayerEntity * player = dynamic_cast<PlayerEntity*>(target);
			player->setAttackDamage((int) ceil((float) player->getAttackDamage() * getValue()));
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
};


#endif //INFINITECONQUEST_PLAYERENTITYATTACKINCREASE_H
