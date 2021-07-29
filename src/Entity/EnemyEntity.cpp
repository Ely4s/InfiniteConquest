//
// Created by Elyas EL IDRISSI on 17/03/2021.
//

#include "EnemyEntity.h"

#include <math.h>

#include "Global/GlobalGame.h"
#include "Qte/QteEnemyBlock.h"
#include "Utils/Random.h"

EnemyEntity::EnemyEntity(const std::string &entityId, const std::string &entityName, Entity::Team team, Entity::Type type, const sf::Vector2f &size, int lifePointMax, int attackDamage)
	: Entity(entityId, entityName, team, type, size, lifePointMax, attackDamage)
{

};

void EnemyEntity::generateAttack(Entity &target)
{
	if (isAlive() && target.isAlive())
	{
		auto blocks = game.getQte().getBlocks<QteEnemyBlock>();
		int blockNbr = blocks.size();
		int luck = 100;
		
		if (blockNbr > 0)
		{
			luck = 300 * (int)pow(1.75, blockNbr);
		}
		
		if (Random::intBetween(0,luck) == 0)
		{
			game.getQte().addBlock(new QteEnemyBlock());
		}
	}
}

int EnemyEntity::attack(Entity &target, bool visualOnly, bool force)
{
	int attackNbr = 0;
	
	if (!visualOnly)
	{
		for (auto &block : game.getQte().getBlocks())
		{
			if (block->getTags().contains(QteTags::ACTIVABLE))
			{
				if (block->active(*this, *this, target))
				{
					attackNbr++;
				}
			}
		}
	}
	
	if (attackNbr > 0 || visualOnly) {Entity::attack(target, force);};
	
	return (attackNbr > 0);
};