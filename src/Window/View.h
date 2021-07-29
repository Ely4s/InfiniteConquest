//
// Created by Elyas EL IDRISSI on 30/03/2021.
//

#ifndef INFINITECONQUEST_VIEW_H
#define INFINITECONQUEST_VIEW_H

#include <SFML/Graphics.hpp>

class View : public sf::View
{

public:
	
	View()=default;
	
	View (const sf::FloatRect &rectangle);
	View (const sf::Vector2f &center, const sf::Vector2f &size);
	
	sf::Vector2f getTopLeft() const;
	
};


#endif //INFINITECONQUEST_VIEW_H
