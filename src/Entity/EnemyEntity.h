//
// Created by Elyas EL IDRISSI on 17/03/2021.
//

#ifndef INFINITECONQUEST_ENEMYENTITY_H
#define INFINITECONQUEST_ENEMYENTITY_H

#include "Entity.h"

class EnemyEntity : public Entity
{

public:
	
	EnemyEntity() = default;
	EnemyEntity(const std::string &entityId, const std::string &entityName, Entity::Team team, Entity::Type type, const sf::Vector2f &size, int lifePointMax, int attackDamage);
	
	void generateAttack(Entity &target) override;
	int attack(Entity &target, bool visualOnly = false, bool force = false) override;
};


#endif //INFINITECONQUEST_ENEMYENTITY_H
