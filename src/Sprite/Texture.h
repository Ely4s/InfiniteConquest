//
// Created by Elyas EL IDRISSI on 06/03/2021.
//

#ifndef INFINITECONQUEST_TEXTURE_H
#define INFINITECONQUEST_TEXTURE_H

#include <SFML/Graphics.hpp>

class Texture : public sf::Texture
{

public:
	
	Texture() = default;
	Texture(const Texture & texture);
	explicit Texture(const std::string &fileName);
	~Texture() = default;
	
};


#endif //INFINITECONQUEST_TEXTURE_H
