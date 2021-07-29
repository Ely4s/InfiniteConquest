//
// Created by Elyas EL IDRISSI on 03/04/2021.
//

#ifndef INFINITECONQUEST_ENTITYSTATS_H
#define INFINITECONQUEST_ENTITYSTATS_H

#include "Gauge/LifeGauge.h"
#include "Text/Text.h"
#include "Entity/Entity.h"
#include "Sprite/Texture.h"
#include <string>

template <class T> class EntityStats : public Sprite
{

public:
	
	EntityStats() = default;
	EntityStats(const Texture &texture, const sf::Vector2f &size);
	EntityStats(const Texture &texture, const sf::Vector2f &size, T &target);
	
	void refresh();
	
	void lifeGaugeRefresh();
	void lifeTextRefresh();
	void lifeMaxTextRefresh();
	void attackTextRefresh();
	
	T *getTarget() const;
	
	virtual void setTarget(T * entityTarget);
	
	LifeGauge &getLifeGauge();
	const LifeGauge &getLifeGauge() const;
	void setLifeGauge(const LifeGauge &lifeGauge);
	
	Text &getLifeText();
	const Text &getLifeText() const;
	void setLifeText(const Text &lifeText);
	
	Text &getLifeMaxText();
	const Text &getLifeMaxText() const;
	void setLifeMaxText(const Text &lifeMaxText);
	
	Text &getAttackText();
	const Text &getAttackText() const;
	void setAttackText(const Text &attackText);
	
	void setPosition(float x, float y) override;
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	void setOrigin(const sf::Vector2f &origin) override;


protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;


private:
	
	T * target = nullptr;
	
	LifeGauge lifeGauge;
	
	Text lifeText;
	Text lifeMaxText;
	Text attackText;
};


template<class T>
EntityStats<T>::EntityStats(const Texture &texture, const sf::Vector2f &size) : Sprite(texture, size)
{

};

template<class T>
EntityStats<T>::EntityStats(const Texture &texture, const sf::Vector2f &size, T &target) : EntityStats<T>::EntityStats(texture, size)
{
	setTarget(target);
}

template<class T>
T *EntityStats<T>::getTarget() const
{
	return target;
}

template<class T>
void EntityStats<T>::setTarget(T * entityTarget)
{
	EntityStats::target = entityTarget;
	
	getLifeGauge().setTarget(*entityTarget);
	
	lifeGaugeRefresh();
	lifeTextRefresh();
	lifeMaxTextRefresh();
	attackTextRefresh();
}

template<class T>
LifeGauge &EntityStats<T>::getLifeGauge()
{
	return lifeGauge;
}

template<class T>
const LifeGauge &EntityStats<T>::getLifeGauge() const
{
	return lifeGauge;
}

template<class T>
void EntityStats<T>::setLifeGauge(const LifeGauge &lifeGauge)
{
	EntityStats::lifeGauge = lifeGauge;
}

template<class T>
Text &EntityStats<T>::getLifeText()
{
	return lifeText;
}

template<class T>
const Text &EntityStats<T>::getLifeText() const
{
	return lifeText;
}

template<class T>
void EntityStats<T>::setLifeText(const Text &lifeText)
{
	EntityStats::lifeText = lifeText;
}

template<class T>
Text &EntityStats<T>::getLifeMaxText()
{
	return lifeMaxText;
}

template<class T>
const Text &EntityStats<T>::getLifeMaxText() const
{
	return lifeMaxText;
}

template<class T>
void EntityStats<T>::setLifeMaxText(const Text &lifeMaxText)
{
	EntityStats::lifeMaxText = lifeMaxText;
}

template<class T>
Text &EntityStats<T>::getAttackText()
{
	return attackText;
}

template<class T>
const Text &EntityStats<T>::getAttackText() const
{
	return attackText;
}

template<class T>
void EntityStats<T>::setAttackText(const Text &attackText)
{
	EntityStats::attackText = attackText;
}

template<class T>
void EntityStats<T>::refresh()
{
	(getTarget()) ? setTarget(getTarget()) : void();
}

template<class T>
void EntityStats<T>::lifeGaugeRefresh()
{
	getLifeGauge().refresh();
}

template<class T>
void EntityStats<T>::lifeTextRefresh()
{
	getLifeText().setString(std::to_string(getTarget()->getLifePoint()));
};

template<class T>
void EntityStats<T>::lifeMaxTextRefresh()
{
	getLifeMaxText().setString(std::to_string(getTarget()->getLifePointMax()));
};

template<class T>
void EntityStats<T>::attackTextRefresh()
{
	getAttackText().setString(std::to_string(getTarget()->getAttackDamage()));
}

template<class T>
void EntityStats<T>::setPosition(float x, float y)
{
	sf::Vector2f offset = {x - getPosition().x, y - getPosition().y};
	Sprite::setPosition(x, y);
	
	getLifeGauge().move(offset.x, offset.y);
	getLifeText().move(offset.x, offset.y);
	getLifeMaxText().move(offset.x, offset.y);
	getAttackText().move(offset.x, offset.y);
}

template<class T>
void EntityStats<T>::setPosition(const sf::Vector2f &position)
{
	EntityStats<T>::setPosition(position.x, position.y);
}

template<class T>
void EntityStats<T>::setOrigin(float x, float y)
{
	sf::Vector2f offset = {x - getOrigin().x, y - getOrigin().y};
	Sprite::setOrigin(x, y);
	
	getLifeGauge().setOrigin(getLifeGauge().getOrigin().x + offset.x, getLifeGauge().getOrigin().y + offset.y);
	getLifeText().setOrigin(getLifeText().getOrigin().x + offset.x, getLifeText().getOrigin().y + offset.y);
	getLifeMaxText().setOrigin(getLifeMaxText().getOrigin().x + offset.x, getLifeMaxText().getOrigin().y + offset.y);
	getAttackText().setOrigin(getAttackText().getOrigin().x + offset.x, getAttackText().getOrigin().y + offset.y);
}

template<class T>
void EntityStats<T>::setOrigin(const sf::Vector2f &origin)
{
	EntityStats<T>::setOrigin(origin.x, origin.y);
}

template<class T>
void EntityStats<T>::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Sprite::draw(target, states);
	
	target.draw(getLifeGauge());
	target.draw(getLifeText());
	target.draw(getLifeMaxText());
	target.draw(getAttackText());
}

#endif //INFINITECONQUEST_ENTITYSTATS_H
