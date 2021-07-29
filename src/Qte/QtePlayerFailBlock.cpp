//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#include "QtePlayerFailBlock.h"
#include "Global/GlobalGame.h"
#include "Utils/Random.h"

QtePlayerFailBlock::QtePlayerFailBlock() : QteBlock(Texture(), sf::Vector2f(40, 40), GameEntityRole::ENTITYROLE_ENEMY, GameEntityRole::Role::ENTITYROLE_PLAYER, 1.3)
{
	const int min = (int)(game.getQte().getBar().getPosition().x + getOrigin().x);
	const int max = (int)(game.getQte().getBar().getPosition().x + game.getQte().getBar().getTextureRect().width - getOrigin().x);
	
	setPosition((float)Random::intBetween(min, max), game.getQte().getBar().getPosition().y + game.getQte().getBar().getTextureRect().height/2.f);
}

void QtePlayerFailBlock::update()
{
	void();
}

bool QtePlayerFailBlock::active(const Entity &entity, Entity &entitySource, Entity &entityTarget)
{
	if (getTags().contains(QteTags::ACTIVABLE) && entitySource.getRole() == getSource() && entityTarget.getRole() == getTarget())
	{
		if (entity.getRole() == getSource())
		{
			entityTarget.setLifePoint(entityTarget.getLifePoint() - entitySource.getAttackDamage());
			
			game.getQte().getCursor().setDefaultSpeed();
			
			getTags().remove(QteTags::ACTIVABLE);
			getTags().add(QteTags::DELETABLE);
			
			return true;
		}
	}
	
	return false;
}

void QtePlayerFailBlock::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	void();
};