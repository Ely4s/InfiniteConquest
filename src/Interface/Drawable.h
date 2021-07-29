//
// Created by Elyas EL IDRISSI on 22/03/2021.
//

#ifndef INFINITECONQUEST_DRAWABLE_H
#define INFINITECONQUEST_DRAWABLE_H

#include <SFML/Graphics.hpp>
#include <thread>

class Drawable : public sf::Drawable
{

protected:
	
	Drawable() = default;

	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
	
};


#endif //INFINITECONQUEST_DRAWABLE_H
