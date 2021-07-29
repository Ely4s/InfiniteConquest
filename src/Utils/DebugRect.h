//
// Created by Elyas EL IDRISSI on 03/04/2021.
//

#ifndef INFINITECONQUEST_DEBUGRECT_H
#define INFINITECONQUEST_DEBUGRECT_H

#include <SFML/Graphics.hpp>

class DebugRect : public sf::RectangleShape
{

public:
	
	DebugRect(sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Red, float thickness = 1);
};


#endif //INFINITECONQUEST_DEBUGRECT_H
