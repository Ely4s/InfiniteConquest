//
// Created by Elyas EL IDRISSI on 06/04/2021.
//

#include "Background.h"

#include "Global/GlobalTextureManager.h"
#include "Utils/DebugRect.h"
#include <math.h>

Background::Background(const std::string& textureId, const sf::Vector2f &selfSize, const sf::Vector2f &size, float speed, int dirX)
{
	setSize(size);
	setSpeed(speed);
	setDirX(dirX);
	
	int stop = (int)ceil(selfSize.x / size.x) + 2;
	
	for(int it = 0; it < stop; it++)
	{
		getBackgrounds().push_back(Sprite(tm.get(textureId), {size}));
		getBackgrounds().at(it).setPosition(size.x * (float)it, 0);
	}
}

float Background::getMaxX()
{
	float x = 0;
	
	for(auto & background : getBackgrounds())
	{
		if(background.getPosition().x + background.getSize().x > x)
		{
			x = (background.getPosition().x + background.getSize().x);
		}
	}
	
	return x;
};

float Background::getMinX()
{
	float x = 0;
	
	for(auto & background : getBackgrounds())
	{
		if(background.getPosition().x > x)
		{
			x = (background.getPosition().x);
		}
	}
	
	return x;
};


void Background::update()
{
	for(auto & background : getBackgrounds())
	{
		background.move((float)getDirX() * getSpeed(), 0);

		if (dirX == - 1 && background.getPosition().x + background.getSize().x <= getPosition().x)
		{
			background.setPosition(getMaxX() + (float)getDirX() * getSpeed(), background.getPosition().y);
		}
		else if (dirX == 1 && background.getPosition().x >= getPosition().x + getSize().x)
		{
			background.setPosition(getMinX(), background.getPosition().y);
		}
	}
};

std::vector<Sprite> &Background::getBackgrounds()
{
	return backgrounds;
}

const std::vector<Sprite> &Background::getBackgrounds() const
{
	return backgrounds;
}

void Background::setBackgrounds(const std::vector<Sprite> &backgrounds)
{
	Background::backgrounds = backgrounds;
}

float Background::getSpeed() const
{
	return speed;
}

void Background::setSpeed(float speed)
{
	Background::speed = speed;
}

int Background::getDirX() const
{
	return dirX;
}

void Background::setDirX(int dirX)
{
	Background::dirX = dirX;
}

void Background::setPosition(float x, float y)
{
	sf::Vector2f offset = {x - getPosition().x, y - getPosition().y};
	Transformable::setPosition(x, y);
	
	for(auto & background : getBackgrounds())
	{
		background.move(offset.x, offset.y);
	}
}

void Background::setPosition(const sf::Vector2f &position)
{
	setPosition(position.x, position.y);
}

void Background::setOrigin(float x, float y)
{
	sf::Vector2f offset = {x - getOrigin().x, y - getOrigin().y};
	Transformable::setOrigin(x, y);
	
	for(auto & background : getBackgrounds())
	{
		background.setOrigin(background.getOrigin().x + offset.x, background.getOrigin().y + offset.y);
	}
	
}

void Background::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

void Background::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(auto & background : getBackgrounds())
	{
		target.draw(background);
	}
}