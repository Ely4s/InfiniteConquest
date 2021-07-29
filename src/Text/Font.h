//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#ifndef INFINITECONQUEST_FONT_H
#define INFINITECONQUEST_FONT_H

#include <SFML/Graphics.hpp>

class Font : public sf::Font
{

public:
	
	Font() = default;
	Font(const Font &font);
	explicit Font(const std::string &fileName);
	~Font() = default;
};


#endif //INFINITECONQUEST_FONT_H
