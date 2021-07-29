//
// Created by Elyas EL IDRISSI on 30/03/2021.
//

#ifndef INFINITECONQUEST_WINDOW_H
#define INFINITECONQUEST_WINDOW_H

#include <SFML/Graphics.hpp>
#include "View.h"

class Window : public sf::RenderWindow
{

public:
	
	Window() : sf::RenderWindow(){};
	Window(sf::VideoMode videoMode, const std::string &title, sf::Uint32 style, const sf::ContextSettings &settings);
	
	void setView(const View &view);
	const View &getView() const;
	const View &getDefaultView() const;
};


#endif //INFINITECONQUEST_WINDOW_H
