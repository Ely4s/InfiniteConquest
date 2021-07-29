//
// Created by Elyas EL IDRISSI on 28/02/2021.
//

#include "Entity.h"
#include "Utils/DebugRect.h"

Entity::Entity(const std::string &entityId, const std::string &entityName, Entity::Team team, Entity::Type type, const sf::Vector2f &size, int lifePointMax, int attackDamage)
{
	setEntityId(entityId);
	setEntityName(entityName);
	setTeam(team);
	setType(type);
	setSize(size);
	setLifePointMax(lifePointMax);
	setLifePoint(getLifePointMax());
	setAttackDamage(attackDamage);
}

bool Entity::isIdling() const
{
	return getState() == Entity::State::IDLE;
};

void Entity::idle(bool force)
{
	!isIdling() || force ? setState(Entity::State::IDLE) : void();
};

bool Entity::isRunning() const
{
	return getState() == Entity::State::RUN;
};

void Entity::run(bool force)
{
	!isRunning() || force ? setState(Entity::State::RUN) : void();
};

bool Entity::isAttacking() const
{
	return getState() == Entity::State::ATTACK;
};

int Entity::attack(Entity &target, bool visualOnly, bool force)
{
	(!isAttacking() || force) ? setState(Entity::State::ATTACK) : void();
	return 0;
}

bool Entity::isDying() const
{
	return getState() == Entity::State::DEATH;
}

void Entity::die(bool force)
{
	!isDying() || force ? setState(Entity::State::DEATH) : void();
};

bool Entity::isAlive() const
{
	return getLifePoint() > 0;
};

bool Entity::isDead() const
{
	return getLifePoint() <= 0;
};

const std::string &Entity::getEntityId() const
{
	return entityId;
}

void Entity::setEntityId(const std::string &entityId)
{
	Entity::entityId = entityId;
}

const std::string &Entity::getEntityName() const
{
	return entityName;
}

void Entity::setEntityName(const std::string &entityName)
{
	Entity::entityName = entityName;
}

Entity::Team Entity::getTeam() const
{
	return team;
}

GameEntityRole::Role Entity::getRole() const
{
	return role;
}

Entity & Entity::setRole(GameEntityRole::Role role)
{
	Entity::role = role;
	
	return *this;
}

Entity * Entity::setTeam(Entity::Team team)
{
	Entity::team = team;
	
	return this;
}

Entity::Type Entity::getType() const
{
	return type;
}

void Entity::setType(Entity::Type type)
{
	Entity::type = type;
}

Entity::State Entity::getState() const
{
	return state;
}

void Entity::setState(Entity::State state)
{
	Entity::state = state;
	getSprite().goToFirstStep();
}

int Entity::getAttackDamage() const
{
	return atkDamage;
}

void Entity::setAttackDamage(int atkDamage)
{
	Entity::atkDamage = (atkDamage < 0) ? 0 : atkDamage;
}

int Entity::getLifePointMax() const
{
	return lifePointMax;
}

void Entity::setLifePointMax(int lifePointMax)
{
	Entity::lifePointMax = (lifePointMax < 0) ? 0 : lifePointMax;
	(getLifePoint() > getLifePointMax()) ? setLifePoint(getLifePointMax()) : void();
}

int Entity::getLifePoint() const
{
	return lifePoint;
}

void Entity::setLifePoint(int lifePoint)
{
	Entity::lifePoint = (lifePoint < 0) ? 0 : (lifePoint > getLifePointMax()) ? getLifePointMax() : lifePoint;
}

const SpriteSheet &Entity::getSprite() const
{
	return sprites.at(STATES_LABEL.at(state));
};

SpriteSheet &Entity::getSprite()
{
	return sprites.at(STATES_LABEL.at(state));
};

const SpriteSheet &Entity::getSprite(const std::string &spriteId) const
{
	return sprites.at(spriteId);
};

SpriteSheet &Entity::getSprite(const std::string &spriteId)
{
	return sprites.at(spriteId);
};

void Entity::setSprite(const std::string &spriteId, const SpriteSheet &sprite)
{
	sprites.insert({spriteId, sprite});
};

const sf::Vector2f &Entity::getPosition() const
{
	return Transformable::getPosition();
};

void Entity::setPosition(float x, float y)
{
	sf::Vector2f offSet = {x - getPosition().x, y - getPosition().y};
	Transformable::setPosition(x, y);
	
	for (auto & element : sprites) {element.second.setPosition(x,y);} // MODIF
}

void Entity::setPosition(const sf::Vector2f &position)
{
	Transformable::setPosition(position);
}

float Entity::getRotation() const
{
	return Transformable::getRotation();
}

void Entity::setRotation(float angle)
{
	float offSet = angle - getRotation();
	Transformable::setRotation(angle);
	
	for (auto & element : sprites) {element.second.setRotation(element.second.getRotation() + offSet);}
}

const sf::Vector2f &Entity::getOrigin() const
{
	return Transformable::getOrigin();
}

void Entity::setOrigin(float x, float y)
{
	Transformable::setOrigin(x, y);
	//for (auto & element : sprites) {element.second.setPosition(getPosition());}
}

void Entity::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

void Entity::flip()
{
	Flippable::flip();
	Transformable::flipOrigin();
	for (auto &element : sprites) {element.second.flip();}
//	for (auto & element : sprites) {element.second.setPosition(getPosition());}
}

void Entity::flip(Flippable::Side side)
{
	//for (auto &element : sprites) {element.second.Flippable::flip(side);}
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(getSprite(), states);
}
