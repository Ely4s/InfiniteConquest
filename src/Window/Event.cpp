//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#include "Event.h"

void Event::resetEvents(Window &window)
{
	events.clear();
	sf::Event e{};
	while(window.pollEvent(e)) {events.push_back(e);};
	
};

bool Event::hasEventTypeAs(const sf::Event::EventType &type) const
{
	for ( auto &event : events)
	{
		if (event.type == type)
		{
			return true;
		}
	}
	
	return false;
};

bool Event::hasEventKeyCodeAs(const sf::Keyboard::Key &keyCode) const
{
	for ( auto &event : events)
	{
		if (event.key.code == keyCode)
		{
			return true;
		}
	}
	
	return false;
};