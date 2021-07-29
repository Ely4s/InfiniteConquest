//
// Created by Elyas EL IDRISSI on 30/03/2021.
//

#include "View.h"

View::View(const sf::FloatRect &rectangle) : sf::View(rectangle){;};
View::View(const sf::Vector2f &center, const sf::Vector2f &size) : sf::View(center, size){;};

sf::Vector2f View::getTopLeft() const
{
	return {getCenter().x - (getSize().x/2.f), getCenter().y - (getSize().y/2.f)};
};