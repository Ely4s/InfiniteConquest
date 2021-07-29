//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#include "Font.h"

Font::Font(const Font &font) : sf::Font(font){;}

Font::Font(const std::string &fileName) : Font()
{
	loadFromFile(fileName);
}