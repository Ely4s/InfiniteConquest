//
// Created by Elyas EL IDRISSI on 27/02/2021.
//

#include "SpriteSheet.h"
#include <iostream>

SpriteSheet::SpriteSheet() : Sprite()
{

};

SpriteSheet::SpriteSheet(const Texture &texture, float secondPerFrame) : Sprite(texture)
{
	setSecondPerFrame(secondPerFrame);
	setFrameNbr( (int)( ((float)(getTexture()->getSize().x)) / ((float)(getTextureRect().width)) ) );
};

SpriteSheet::SpriteSheet(const Texture &texture, const sf::Vector2f &size, float secondPerFrame) : Sprite(texture, size)
{
	setSecondPerFrame(secondPerFrame);
	setFrameNbr( (int)( ((float)(getTexture()->getSize().x)) / ((float)(getTextureRect().width)) ) );
};

SpriteSheet::SpriteSheet(const Texture &texture, const sf::Vector2f &size, const sf::IntRect &textureRect, float secondPerFrame) : Sprite(texture, size, textureRect)
{
	setSecondPerFrame(secondPerFrame);
	setFrameNbr( (int)( ((float)(getTexture()->getSize().x)) / ((float)(getTextureRect().width)) ) );
};

void SpriteSheet::setFrameIt(float frameIt)
{
	Animable::setFrameIt(frameIt);
	setTextureRect(sf::IntRect( ( getTextureRect().width * (int)getFrameIt() ),  getTextureRect().top, getTextureRect().width,  getTextureRect().height ) );
}



