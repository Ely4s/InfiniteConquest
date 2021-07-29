//
// Created by Elyas EL IDRISSI on 03/04/2021.
//

#ifndef INFINITECONQUEST_ENEMYENTITYSTATS_H
#define INFINITECONQUEST_ENEMYENTITYSTATS_H

#include "Sprite/Sprite.h"
#include "Gauge/LifeGauge.h"
#include "Gauge/RageGauge.h"
#include "Text/Text.h"
#include "Entity/FamiliarEntity.h"
#include "Stats/EntityStats.h"

class EnemyEntityStats : public EntityStats<Entity>
{

public:
	
	EnemyEntityStats();
	EnemyEntityStats(Entity * enemyTarget);

protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //INFINITECONQUEST_ENEMYENTITYSTATS_H
