//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYFACTORY_H
#define INFINITECONQUEST_PLAYERENTITYFACTORY_H

#include "Factory.h"
#include "Entity/PlayerEntity.h"
#include "Global/GlobalTextureManager.h"
#include "Global/GlobalSpriteSheetFactory.h"

class PlayerEntityFactory : public Factory<PlayerEntity>
{

public:
	
	PlayerEntityFactory(){init();};
	
	void init() override
	{
		PlayerEntity e;
		Ids it;
		
		//-------------------------------- RogueMan --------------------------------//
		
		it = {"RogueMan", "RogueMan"};
		e = PlayerEntity(it.id, it.name, Entity::TEAM_PLAYER, Entity::TYPE_PLAYER, sf::Vector2f(300,300), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(135, 245);
		e.setRole(GameEntityRole::ENTITYROLE_PLAYER);
		add(it.id, e);
		
	};
	
};

#endif //INFINITECONQUEST_PLAYERENTITYFACTORY_H
