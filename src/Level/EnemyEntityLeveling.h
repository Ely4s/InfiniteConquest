//
// Created by Elyas EL IDRISSI on 05/04/2021.
//

#ifndef INFINITECONQUEST_ENEMYENTITYLEVELING_H
#define INFINITECONQUEST_ENEMYENTITYLEVELING_H

#include "Entity/EnemyEntity.h"

#include <math.h>

class EnemyEntityLeveling
{

public:
	
	static void apply(EnemyEntity &enemy, unsigned int level)
	{
		float coef = pow(1.15f, level-1);
		
		enemy.setLifePointMax(ceil((float)enemy.getLifePointMax() * coef));
		enemy.setLifePoint(ceil((float)enemy.getLifePoint() * coef));
		enemy.setAttackDamage(ceil((float)enemy.getAttackDamage() * coef));
	}
};


#endif //INFINITECONQUEST_ENEMYENTITYLEVELING_H
