//
// Created by Elyas EL IDRISSI on 27/02/2021.
//

#ifndef INFINITECONQUEST_SPRITESHEET_H
#define INFINITECONQUEST_SPRITESHEET_H

#include "Sprite.h"
#include "Interface/Animable.h"

class SpriteSheet : public Sprite, public Animable
{

public:
	
	SpriteSheet();
	SpriteSheet(const Texture &texture, float secondPerFrame = 1);
	SpriteSheet(const Texture &texture, const sf::Vector2f &size, float secondPerFrame = 1);
	SpriteSheet(const Texture &texture, const sf::Vector2f &size, const sf::IntRect &textureRect, float secondPerFrame = 1);
	
	~SpriteSheet() = default;

protected:
	
	void setFrameIt(float frameIt);
};


#endif //INFINITECONQUEST_SPRITESHEET_H
