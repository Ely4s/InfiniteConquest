//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_FAMILIARENTITYATTACKINCREASE_H
#define INFINITECONQUEST_FAMILIARENTITYATTACKINCREASE_H

#include "FamiliarEntityBonus.h"

#include <math.h>

class FamiliarEntityAttackIncrease : public FamiliarEntityBonus
{

	public:
	
	FamiliarEntityAttackIncrease() : FamiliarEntityBonus(1.2f, "+ Degat Familier"){};
	
	
	bool apply(Entity * target) override
	{
		if (FamiliarEntityBonus::apply(target))
		{
			FamiliarEntity *familiar = (FamiliarEntity *) target;
			familiar->setAttackDamage((int) ceil((float) familiar->getAttackDamage() * getValue()));
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
};


#endif //INFINITECONQUEST_FAMILIARENTITYATTACKINCREASE_H
