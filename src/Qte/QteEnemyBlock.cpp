//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#include "QteEnemyBlock.h"
#include "Global/GlobalTextureManager.h"
#include "Global/GlobalGame.h"
#include "Entity/PlayerEntity.h"

QteEnemyBlock::QteEnemyBlock() : QteBlock(tm.get("qte_block_enemy"),sf::Vector2f(40, 40), GameEntityRole::ENTITYROLE_ENEMY, GameEntityRole::Role::ENTITYROLE_PLAYER, 3.f)
{
	setPosition(game.getQte().getBar().getTopLeft().x + game.getQte().getBar().getSize().x - getOrigin().x - game.getQte().getBar().getRightOffset(), game.getQte().getBar().getTopLeft().y + game.getQte().getBar().getSize().y/2.f);
}

void QteEnemyBlock::update()
{
	/*float posMin = qte.getBar().getPosition().x + qte.getBar().getTextureRect().width;
	float posMax = qte.getBar().getPosition().x;
	float pos = getPosition().x;
	float speed = (posMin-pos)/(posMin-posMax);
	
	move(-1 * ( getSpeed() + (1.5 * speed) ), 0);*/
	
	move(-1 * getSpeed(), 0);
}

bool QteEnemyBlock::active(const Entity &entity, Entity &entitySource, Entity &entityTarget)
{
	if (getTags().contains(QteTags::ACTIVABLE) && entitySource.getRole() == getSource() && entityTarget.getRole() == getTarget())
	{
		if (entity.getRole() == getSource())
		{
			if (getTopLeft().x <= game.getQte().getBar().getTopLeft().x + game.getQte().getBar().getLeftOffset())
			{
				entityTarget.setLifePoint(entityTarget.getLifePoint() - entitySource.getAttackDamage());
				game.getQte().getCursor().speedDown();
				dynamic_cast<PlayerEntity*>(&entityTarget)->rageDown();
				
				getTags().remove(QteTags::ACTIVABLE);
				getTags().add(QteTags::DELETABLE);
				
				return true;
			}
		}
	}
	
	if (getTags().contains(QteTags::ACTIVABLE) && entitySource.getRole() == getTarget() && entityTarget.getRole() == getSource())
	{
		if (entity.getRole() == getTarget())
		{
			if (game.getEvent().hasEventTypeAs(sf::Event::KeyPressed ) && game.getEvent().hasEventKeyCodeAs(sf::Keyboard::Space) && getGlobalBounds().intersects(game.getQte().getCursor().getGlobalBounds()))
			{
				game.getQte().getCursor().speedUp();
				dynamic_cast<PlayerEntity*>(&entitySource)->rageUp();
				
				getTags().remove(QteTags::ACTIVABLE);
				getTags().add(QteTags::DELETABLE);
				
				return true;
			}
		}
	}
	
	return false;
};