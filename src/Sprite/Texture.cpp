//
// Created by Elyas EL IDRISSI on 06/03/2021.
//

#include "Texture.h"

Texture::Texture(const Texture &texture) : sf::Texture(texture){;}

Texture::Texture(const std::string &fileName) : sf::Texture()
{
	loadFromFile(fileName);
}


