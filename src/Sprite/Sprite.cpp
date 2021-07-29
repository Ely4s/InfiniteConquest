//
// Created by Elyas EL IDRISSI on 27/02/2021.
//

#include "Sprite.h"

#include <utility>
#include <stdio.h>
#include <math.h>

Sprite::Sprite()
{
	setScale(sf::Vector2f(1, 1));
	setBaseScale(sf::Vector2f(1, 1));
	setTextureScale(sf::Vector2f(1, 1));
};

Sprite::Sprite(const Texture & texture) : Sprite()
{
	sprite.setTexture(texture,true);
	setSize({(float)texture.getSize().x, (float)texture.getSize().y});
	setTextureRect(sf::IntRect(0, 0, texture.getSize().x , texture.getSize().y));
};

Sprite::Sprite(const Texture &texture, const sf::Vector2f &size) : Sprite(texture)
{
	setSize(size);
};

Sprite::Sprite(const Texture &texture, const sf::Vector2f &size, const sf::IntRect &textureRect) : Sprite(texture, size)
{
	setTextureRect(textureRect);
};

const sf::Vector2f &Sprite::getPosition() const
{
	return sprite.getPosition();
};

void Sprite::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
};

void Sprite::setPosition(const sf::Vector2f &position)
{
	setPosition(position.x, position.y);
};

const sf::Vector2f &Sprite::getSize() const
{
	return Transformable::getSize();
}

void Sprite::setSize(float w, float h)
{
	Transformable::setSize(w, h);
	updateScale();
}

void Sprite::setSize(const sf::Vector2f &size)
{
	setSize(size.x, size.y);
}

const sf::Vector2f &Sprite::getOrigin() const
{
	return Transformable::getOrigin();
}

void Sprite::setOrigin(float x, float y)
{
	Transformable::setOrigin(x,y);
	sprite.setOrigin(x * (getTextureRect().width / getSize().x), y * (getTextureRect().height / getSize().y));
}

void Sprite::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

float Sprite::getRotation() const
{
	return sprite.getRotation();
}

void Sprite::setRotation(float angle)
{
	sprite.setRotation(angle);
}

const sf::Vector2f &Sprite::getScale() const
{
	return getBaseScale();
}

void Sprite::setScale(float factorX, float factorY)
{
	setBaseScale(sf::Vector2f(factorX, factorY));
	sprite.setScale(sf::Vector2f(getBaseScale().x * getTextureScale().x, getBaseScale().y * getTextureScale().y));
}

void Sprite::setScale(const sf::Vector2f &factors)
{
	setScale(factors.x, factors.y);
}

const sf::Vector2f &Sprite::getTextureScale() const
{
	return textureScale;
}

void Sprite::setTextureScale(const sf::Vector2f &textureScale)
{
	Sprite::textureScale = textureScale;
}

const sf::Vector2f &Sprite::getBaseScale() const
{
	return baseScale;
}

void Sprite::setBaseScale(const sf::Vector2f &baseScale)
{
	Sprite::baseScale = baseScale;
}

void Sprite::updateScale()
{
	setTextureScale(sf::Vector2f(getSize().x / (float) getTextureRect().width, getSize().y / (float) getTextureRect().height));
	setScale(getScale());
};

const Texture *Sprite::getTexture() const
{
	return (Texture*)sprite.getTexture();
}

void Sprite::setTexture(const Texture &texture, bool resetRect)
{
	sprite.setTexture(texture, resetRect);
}

const sf::IntRect &Sprite::getTextureRect() const
{
	return unflipTextureRect;
}

//TODO: Faire que le textureRect soit en fonction de Size et non pas de la texture

void Sprite::setTextureRect(const sf::IntRect &textureRect)
{
	const Texture * texture = getTexture();
	
	const sf::Vector2u a = texture->getSize();
	
	sf::IntRect b = textureRect;
	
	int left = (textureRect.left < 0) ? 0 : (textureRect.left > (int)getTexture()->getSize().x) ? (int)getTexture()->getSize().x : textureRect.left;
	int top = (textureRect.top < 0) ? 0 : (textureRect.top > (int)getTexture()->getSize().y) ? (int)getTexture()->getSize().y : textureRect.top;
	int widht = (textureRect.width < 0) ? 0 : (left + textureRect.width > (int)getTexture()->getSize().x) ? (int)getTexture()->getSize().x - left : textureRect.width;
	int height = (textureRect.height < 0) ? 0 : (top + textureRect.height > (int)getTexture()->getSize().y) ? (int)getTexture()->getSize().y - top : textureRect.height;
	
	unflipTextureRect = {left, top, widht, height};

	!getIsFlip() ?

		setRealTextureRect({left, top, widht, height}) :
		setRealTextureRect(sf::IntRect(widht + left, top, -widht, height));
	
	updateScale();
}

const sf::IntRect &Sprite::getRealTextureRect() const
{
	return getTextureRect();
}

void Sprite::setRealTextureRect(const sf::IntRect &realTextureRect)
{
	sprite.setTextureRect(realTextureRect);
}

const sf::Color &Sprite::getColor() const
{
	return sprite.getColor();
}

void Sprite::setColor(const sf::Color &color)
{
	sprite.setColor(color);
}

sf::FloatRect Sprite::getLocalBounds() const
{
	return sprite.getLocalBounds();
}

sf::FloatRect Sprite::getGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

void Sprite::flip()
{
	Flippable::flip();
	setTextureRect(getTextureRect());
	Transformable::flipOrigin();
}

void Sprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}