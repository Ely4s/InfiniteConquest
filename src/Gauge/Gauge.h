//
// Created by Elyas EL IDRISSI on 28/02/2021.
//

#ifndef INFINITECONQUEST_GAUGE_H
#define INFINITECONQUEST_GAUGE_H

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Sprite/Sprite.h"
#include "Interface/Animable.h"
#include <math.h>

template <class TargetClass>
class Gauge : public Sprite, public Animable
{

public:
	
	Gauge() = default;
	Gauge(const Texture &texture, const sf::Vector2i &size);
	Gauge(const Texture &texture, const sf::Vector2i &size, TargetClass &target);
	
	void refresh();
	
	const sf::Vector2i &getFrameFullSize() const;
	void setFrameFullSize(const sf::Vector2i &frameFullSize);

	TargetClass *getTarget() const;
	void setTarget(TargetClass &target);
	
	void flip() override;

protected:
	
	TargetClass * target;
	
	void setFrameIt(float frameIt) override;
	
	float getPercent() const;
	virtual void setPercent(float percent);
	
	virtual float getPercentFromTarget() const = 0;
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	
	float percent{};
	
	sf::Vector2i frameFullSize{};
};

template<class TargetClass>
Gauge<TargetClass>::Gauge(const Texture &texture, const sf::Vector2i &size)
		: Sprite(texture, sf::Vector2f(size.x, size.y), sf::IntRect(0, 0, size.x, size.y))
{
	setFrameFullSize(size);
};

template<class TargetClass>
Gauge<TargetClass>::Gauge(const Texture &texture, const sf::Vector2i &size, TargetClass &target) : Gauge<TargetClass>::Gauge(texture, size), target(&target)
{

};

template<class TargetClass>
void Gauge<TargetClass>::refresh()
{
	setPercent(getPercentFromTarget());
};

template<class TargetClass>
float Gauge<TargetClass>::getPercent() const
{
	return percent;
};

template<class TargetClass>
void Gauge<TargetClass>::setPercent(float percent)
{
	Gauge::percent =
			
			(percent < 0) ? 0 :
			(percent > 100) ? 100 :
			percent;
	
	int newWidht = getFrameFullSize().x * (getPercent() / 100.f);

	if (newWidht == 0 && percent != 0)
	{
		newWidht = 1;
	}
	
	(getTexture()) ? setTextureRect(sf::IntRect(0, 0 , getTexture()->getSize().x * ((float)newWidht/(float)getFrameFullSize().x), getTextureRect().height)) : void ();
	setSize(newWidht, getSize().y);
	
	(getIsFlip()) ? setOrigin({getSize().x, getOrigin().y}) : void();
}

template<class TargetClass>
const sf::Vector2i &Gauge<TargetClass>::getFrameFullSize() const
{
	return frameFullSize;
}

template<class TargetClass>
void Gauge<TargetClass>::setFrameFullSize(const sf::Vector2i &frameFullSize)
{
	Gauge::frameFullSize = frameFullSize;
}

template<class TargetClass>
void Gauge<TargetClass>::setFrameIt(float frameIt)
{
	Animable::setFrameIt(frameIt);
	setPercent(getPercent());
}

template<class TargetClass>
void Gauge<TargetClass>::flip()
{
	Sprite::flip();
	
	(getIsFlip()) ? setOrigin({getSize().x, getOrigin().y}) : setOrigin({0, getOrigin().y});
	
}

template<class TargetClass>
TargetClass *Gauge<TargetClass>::getTarget() const
{
	return target;
}

template<class TargetClass>
void Gauge<TargetClass>::setTarget(TargetClass &target)
{
	Gauge::target = &target;
}

template<class TargetClass>
void Gauge<TargetClass>::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Sprite::draw(target, states);
}

#endif //INFINITECONQUEST_GAUGE_H