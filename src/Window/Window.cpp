//
// Created by Elyas EL IDRISSI on 30/03/2021.
//

#include "Window.h"

Window::Window(sf::VideoMode videoMode, const std::string &title, sf::Uint32 style, const sf::ContextSettings &settings) : sf::RenderWindow(videoMode, title, style, settings){}

void Window::setView(const View &view)
{
	RenderTarget::setView(view);
}

const View &Window::getView() const
{
	return (View &&)(RenderTarget::getView());
}

const View &Window::getDefaultView() const
{
	return (View &&)RenderTarget::getDefaultView();
}
