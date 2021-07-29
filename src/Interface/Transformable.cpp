//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#include "Transformable.h"

const sf::Vector2f &Transformable::getPosition() const
{
	return sf::Transformable::getPosition();
}

void Transformable::setPosition(float x, float y)
{
	sf::Transformable::setPosition(x, y);
}

void Transformable::setPosition(const sf::Vector2f &position)
{
	setPosition(position.x, position.y);
}

void Transformable::move(float offsetX, float offsetY)
{
	setPosition(getPosition().x + offsetX, getPosition().y + offsetY);
}

void Transformable::move(const sf::Vector2f &offset)
{
	setPosition(getPosition().x + offset.x, getPosition().y + offset.y);
}

sf::Vector2f Transformable::getTopLeft() const
{
	return {getPosition().x - getOrigin().x, getPosition().y - getOrigin().y};
}

const sf::Vector2f &Transformable::getSize() const
{
	return Transformable::size;
}

void Transformable::setSize(float w, float h)
{
	Transformable::size = sf::Vector2f(w, h);
}

void Transformable::setSize(const sf::Vector2f &size)
{
	setSize(size.x, size.y);
}

void Transformable::scaleSize(float w, float h)
{
	setSize(getSize().x * w, getSize().y * h);
}

void Transformable::scaleSize(const sf::Vector2f &size)
{
	setSize(getSize().x * size.x, getSize().y * size.y);
}

float Transformable::getRotation() const
{
	return sf::Transformable::getRotation();
}

void Transformable::setRotation(float angle)
{
	sf::Transformable::setRotation(angle);
}

void Transformable::rotate(float angle)
{
	setRotation(getRotation() + angle);
}

const sf::Vector2f &Transformable::getScale() const
{
	return sf::Transformable::getScale();
}

void Transformable::setScale(float factorX, float factorY)
{
	sf::Transformable::setScale(factorX, factorY);
}

void Transformable::setScale(const sf::Vector2f &factors)
{
	setScale(factors.x, factors.y);
}

void Transformable::scale(float factorX, float factorY)
{
	setScale(getScale().x * factorX, getScale().y * factorY);
}

void Transformable::scale(const sf::Vector2f &factor)
{
	setScale(getScale().x * factor.x, getScale().y * factor.y);
}

const sf::Vector2f &Transformable::getOrigin() const
{
	return sf::Transformable::getOrigin();
}

void Transformable::setOrigin(float x, float y)
{
	sf::Transformable::setOrigin(x, y);
}

void Transformable::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

void Transformable::flipOrigin()
{
	setOrigin(getSize().x - getOrigin().x, getOrigin().y);
}
