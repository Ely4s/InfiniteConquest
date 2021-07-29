//
// Created by Elyas EL IDRISSI on 03/04/2021.
//

#include "DebugRect.h"

DebugRect::DebugRect(sf::Vector2f position, sf::Vector2f size, sf::Color color, float thickness)
{
	setPosition(position);
	setSize(size);
	setOutlineColor(color);
	setOutlineThickness(thickness);
	setFillColor(sf::Color::Transparent);
}
