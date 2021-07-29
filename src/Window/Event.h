//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#ifndef INFINITECONQUEST_EVENT_H
#define INFINITECONQUEST_EVENT_H

#include <SFML/Graphics.hpp>
#include "Window.h"

class Event
{

public:

	void resetEvents(Window &window);
	bool hasEventTypeAs(const sf::Event::EventType &type) const;
	bool hasEventKeyCodeAs(const sf::Keyboard::Key &keyCode) const;

private:
	
	std::vector<sf::Event> events;
	
};


#endif //INFINITECONQUEST_EVENT_H
