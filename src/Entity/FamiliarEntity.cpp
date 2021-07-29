//
// Created by Elyas EL IDRISSI on 27/03/2021.
//

#include "FamiliarEntity.h"
#include "Utils/Random.h"

FamiliarEntity::FamiliarEntity(const std::string &entityId, const std::string &entityName, EntityTeam::Team team, EntityType::Type type, const sf::Vector2f &size, int lifePointMax, int atkDamage)
		: Entity(entityId, entityName, team, type, size, lifePointMax, atkDamage)
{

}

void FamiliarEntity::generateAttack(Entity &target)
{
	void();
}

int FamiliarEntity::attack(Entity &target, bool visualOnly, bool force)
{
	int attackNbr = 0;
	
	if (isAlive() && target.isAlive())
	{
		if (Random::intBetween(0, 250) == 0)
		{
			target.setLifePoint(target.getLifePoint() - getAttackDamage());
			
			attackNbr++;
		}
	}
	
	if (attackNbr > 0 || visualOnly) {Entity::attack(target, force);};
	
	return (attackNbr > 0);
}
