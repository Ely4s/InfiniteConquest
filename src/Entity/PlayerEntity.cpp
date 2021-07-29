//
// Created by Elyas EL IDRISSI on 17/03/2021.
//

#include "PlayerEntity.h"

#include <math.h>

#include "Global/GlobalGame.h"
#include "Qte/QtePlayerBlock.h"
#include "Qte/QteEnemyBlock.h"
#include "Qte/QtePlayerFailBlock.h"
#include "Utils/Random.h"

PlayerEntity::PlayerEntity(const std::string &entityId, const std::string &entityName, Entity::Team team, Entity::Type type, const sf::Vector2f &size, int lifePointMax, int attackDamage)
		: Entity(entityId, entityName, team, type, size, lifePointMax, attackDamage), rage(0), rageMax(10), rageDamage(0)
{
	setRageDamage((int)((float)getAttackDamage() * 3.f));
}

void PlayerEntity::generateAttack(Entity &target)
{
	if (isAlive() && target.isAlive())
	{
		auto blocks = game.getQte().getBlocks<QtePlayerBlock>();
		int luck = (blocks.empty()) ? 0 : 300 * (int)pow(1.75, blocks.size());
		
		(Random::intBetween(0,luck) == 0) ? game.getQte().addBlock(new QtePlayerBlock()) : void();
	}
};

int PlayerEntity::attack(Entity &target, bool visualOnly, bool force)
{
	int attackNbr = 0;
	int parryNbr = 0;
	
	if (!visualOnly)
	{
		for (auto &block : game.getQte().getBlocks<QtePlayerBlock>())
		{
			if (block->getTags().contains(QteTags::ACTIVABLE))
			{
				if (block->active(*this, *this, target))
				{
					attackNbr++;
				}
			}
		}
		
		for (auto &block : game.getQte().getBlocks<QteEnemyBlock>())
		{
			if (block->getTags().contains(QteTags::ACTIVABLE))
			{
				if (block->active(*this, *this, target))
				{
					parryNbr++;
				}
			}
		}
		
		if (getRage() == getRageMax() && game.getEvent().hasEventTypeAs(sf::Event::KeyPressed ) && game.getEvent().hasEventKeyCodeAs(sf::Keyboard::C))
		{
			target.setLifePoint(target.getLifePoint()-getRageDamage());
			resetRage();
			game.getQte().getCursor().setDefaultSpeed();
			game.getQte().setCursor(game.getQte().getCursor());
			
			attackNbr++;
		}
	}
	
	if (attackNbr > 0 || visualOnly) {Entity::attack(target, force);};
	
	if (!visualOnly && attackNbr == 0 && parryNbr == 0 && game.getEvent().hasEventTypeAs(sf::Event::KeyPressed ) && game.getEvent().hasEventKeyCodeAs(sf::Keyboard::Space))
	{
		resetRage();
		game.getQte().addBlock(new QtePlayerFailBlock());
	}
	
	return (attackNbr > 0);
}

void PlayerEntity::rageUp()
{
	setRage(getRage()+1);
};

void PlayerEntity::rageDown()
{
	setRage(getRage()-1);
};

void PlayerEntity::resetRage()
{
	setRage(0);
};

int PlayerEntity::getRageMax() const
{
	return rageMax;
}

void PlayerEntity::setRageMax(int rageMax)
{
	PlayerEntity::rageMax = rageMax;
}

int PlayerEntity::getRage() const
{
	return rage;
}

void PlayerEntity::setRage(int rage)
{
	PlayerEntity::rage = (rage < 0) ? 0 : (rage > getRageMax()) ? getRageMax() : rage;
}

int PlayerEntity::getRageDamage() const
{
	return rageDamage;
}

void PlayerEntity::setRageDamage(int rageDamage)
{
	PlayerEntity::rageDamage = (rageDamage < 0) ? 0 : rageDamage;
}
