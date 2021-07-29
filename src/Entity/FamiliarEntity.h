//
// Created by Elyas EL IDRISSI on 27/03/2021.
//

#ifndef INFINITECONQUEST_FAMILIARENTITY_H
#define INFINITECONQUEST_FAMILIARENTITY_H

#include "Entity.h"

class FamiliarEntity : public Entity
{

public:
	
	FamiliarEntity() = default;
	FamiliarEntity(const std::string &entityId, const std::string &entityName, Team team, Type type, const sf::Vector2f &size, int lifePointMax, int atkDamage);
	
	void generateAttack(Entity &target) override;
	
	int attack(Entity &target, bool visualOnly = false, bool force = false) override;
};


#endif //INFINITECONQUEST_FAMILIARENTITY_H
