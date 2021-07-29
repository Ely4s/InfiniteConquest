//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#ifndef INFINITECONQUEST_ENEMYENTITYFACTORY_H
#define INFINITECONQUEST_ENEMYENTITYFACTORY_H

#include "Factory.h"
#include "Entity/EnemyEntity.h"
#include "Global/GlobalTextureManager.h"
#include "Global/GlobalSpriteSheetFactory.h"

class EnemyEntityFactory : public Factory<EnemyEntity>
{

public:
	
	EnemyEntityFactory()
	{
		init();
	}
	
	void init()
	{
		EnemyEntity e;
		Ids it;
		
		//-------------------------------- RogueMan --------------------------------//
		
		it = {"Spectral Revenant", "Spectral Revenant"};
		e = EnemyEntity(it.id, it.name, Entity::TEAM_ENEMY, Entity::TYPE_ENEMY, sf::Vector2f(80*3, 80*3), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(37*3, 67*3);
		e.setRole(GameEntityRole::ENTITYROLE_ENEMY);
		e.flip();
		add(it.id, e);
		
		it = {"Death Knell", "Death Knell"};
		e = EnemyEntity(it.id, it.name, Entity::TEAM_ENEMY, Entity::TYPE_ENEMY, sf::Vector2f(120*3, 120*3), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(59*3, 103*3);
		e.setRole(GameEntityRole::ENTITYROLE_ENEMY);
		e.flip();
		add(it.id, e);
		
		it = {"Vorpal Reaver", "RVorpal Reaver"};
		e = EnemyEntity(it.id, it.name, Entity::TEAM_ENEMY, Entity::TYPE_ENEMY, sf::Vector2f(80*3, 80*3), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(34*3, 63*3);
		e.setRole(GameEntityRole::ENTITYROLE_ENEMY);
		e.flip();
		add(it.id, e);
		
		it = {"Grandmaster Variax", "Grandmaster Variax"};
		e = EnemyEntity(it.id, it.name, Entity::TEAM_ENEMY, Entity::TYPE_ENEMY, sf::Vector2f(120*3, 120*3), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(63*3, 103*3);
		e.setRole(GameEntityRole::ENTITYROLE_ENEMY);
		e.flip();
		add(it.id, e);
		
		it = {"Stygian Observer", "Stygian Observer"};
		e = EnemyEntity(it.id, it.name, Entity::TEAM_ENEMY, Entity::TYPE_ENEMY, sf::Vector2f(130*3, 130*3), 100, 10);
		for (const auto& states : Entity::STATES_LABEL) {e.setSprite(states.second, ssf.get(it.id+"_"+states.second));}
		e.setOrigin(64*3, 113*3);
		e.setRole(GameEntityRole::ENTITYROLE_ENEMY);
		e.flip();
		add(it.id, e);
	}
	
};


#endif //INFINITECONQUEST_ENEMYENTITYFACTORY_H
