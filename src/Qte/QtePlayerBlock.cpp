//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#include "QtePlayerBlock.h"

#include "Global/GlobalTextureManager.h"
#include "Global/GlobalGame.h"
#include "Utils/Random.h"

QtePlayerBlock::QtePlayerBlock() : QteBlock(tm.get("qte_block_player"), sf::Vector2f(40, 40), GameEntityRole::ENTITYROLE_PLAYER, GameEntityRole::Role::ENTITYROLE_ENEMY, 1.3)
{
	const int min = (int)(game.getQte().getBar().getTopLeft().x + getOrigin().x + game.getQte().getBar().getLeftOffset());
	const int max = (int)(game.getQte().getBar().getTopLeft().x + game.getQte().getBar().getSize().x - getOrigin().x - game.getQte().getBar().getRightOffset());
	
	setPosition((float)Random::intBetween(min, max), game.getQte().getBar().getTopLeft().y + game.getQte().getBar().getSize().y/2.f);
}

bool QtePlayerBlock::active(const Entity &entity, Entity &entitySource, Entity &entityTarget)
{
	if (getTags().contains(QteTags::ACTIVABLE) && entitySource.getRole() == getSource() && entityTarget.getRole() == getTarget())
	{
		if (entity.getRole() == getSource())
		{
			if (game.getEvent().hasEventTypeAs(sf::Event::KeyPressed ) && game.getEvent().hasEventKeyCodeAs(sf::Keyboard::Space) && getGlobalBounds().intersects(game.getQte().getCursor().getGlobalBounds()))
			{
				entityTarget.setLifePoint(entityTarget.getLifePoint() - entitySource.getAttackDamage());
				
				game.getQte().getCursor().speedUp();
				
				dynamic_cast<PlayerEntity*>(&entitySource)->rageUp();
				
				getTags().remove(QteTags::ACTIVABLE);
				getTags().add(QteTags::DELETABLE);
				
				return true;
			}
		}
	}
	
	return false;
}

void QtePlayerBlock::update()
{
	void();
}
