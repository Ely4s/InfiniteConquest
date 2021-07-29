//
// Created by Elyas EL IDRISSI on 27/03/2021.
//

#ifndef INFINITECONQUEST_FAMILIARENTITYFACTORY_H
#define INFINITECONQUEST_FAMILIARENTITYFACTORY_H

#include "Factory.h"
#include "Entity/FamiliarEntity.h"
#include "Global/GlobalTextureManager.h"

class FamiliarEntityFactory : public Factory<FamiliarEntity>
{

public:
	
	FamiliarEntityFactory(){init();};
	
	void init() override
	{
		FamiliarEntity e;
		Ids it;
		
		//-------------------------------- RogueMan --------------------------------//
		
		it = {"Snow Chaser", "Snow Chaser"};
		e = FamiliarEntity(it.id, it.name, Entity::TEAM_PLAYER, Entity::TYPE_FAMILIAR, sf::Vector2f(80*3,83*3), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(43*3, 63*3);
		e.setRole(GameEntityRole::ENTITYROLE_FAMILIAR);
		add(it.id, e);
	};
};


#endif //INFINITECONQUEST_FAMILIARENTITYFACTORY_H
