//
// Created by Elyas EL IDRISSI on 17/03/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITY_H
#define INFINITECONQUEST_PLAYERENTITY_H

#include "Entity.h"

class PlayerEntity : public Entity
{

public:
	
	PlayerEntity() = default;
	
	PlayerEntity(const std::string &entityId, const std::string &entityName, Entity::Team team, Entity::Type type, const sf::Vector2f &size, int lifePointMax, int attackDamage);
	
	virtual void generateAttack(Entity &target) override;
	int attack(Entity &target, bool visualOnly = false, bool force = false) override;
	
	void resetRage();
	void rageUp();
	void rageDown();
	int getRageMax() const;
	void setRageMax(int rageMax);
	int getRage() const;
	void setRage(int rage);
	
private:
	
	int rageMax{};
	int rage{};
	int rageDamage{};
	
public:
	
	int getRageDamage() const;
	void setRageDamage(int rageDamage);
};


#endif //INFINITECONQUEST_PLAYERENTITY_H
