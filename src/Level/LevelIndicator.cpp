//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#include "LevelIndicator.h"

#include "Global/GlobalTextureManager.h"
#include "Global/GlobalFontManager.h"

LevelIndicator::LevelIndicator() : Sprite(tm.get("level_indicator"), {96, 108}, {0, 0, 96, 108})
{
	setOrigin(getSize().x/2.f, 0);
	
	getText().setFont(fm.get("ice_pixel-7"));
	getText().setAlign(Text::CENTER, Text::MIDDLE);
	getText().setCharacterSize(50);
	getText().setPosition(getPosition().x + 24*2, getPosition().y + 38*2);
}

LevelIndicator::LevelIndicator(unsigned int level) : LevelIndicator()
{
	LevelIndicator::level = level;
	refresh();
}

void LevelIndicator::nextLevel()
{
	setLevel(getLevel()+1);
	refresh();
}

void LevelIndicator::resetLevel()
{
	setLevel(1);
	refresh();
}

void LevelIndicator::refresh()
{
	getText().setString(std::to_string(getLevel()));
};

Text &LevelIndicator::getText()
{
	return text;
}

const Text &LevelIndicator::getText() const
{
	return text;
}

void LevelIndicator::setText(const Text &text)
{
	LevelIndicator::text = text;
}

unsigned int LevelIndicator::getLevel() const
{
	return level;
}

void LevelIndicator::setLevel(unsigned int level)
{
	LevelIndicator::level = level;
}

void LevelIndicator::setPosition(float x, float y)
{
	sf::Vector2f offset = {x - getPosition().x, y - getPosition().y};
	Sprite::setPosition(x, y);
	
	getText().move(offset.x, offset.y);
}

void LevelIndicator::setPosition(const sf::Vector2f &position)
{
	Sprite::setPosition(position.x, position.y);
}

void LevelIndicator::setOrigin(float x, float y)
{
	sf::Vector2f offset = {x - getOrigin().x, y - getOrigin().y};
	Sprite::setOrigin(x, y);
	
	getText().setOrigin(getText().getOrigin().x + offset.x, getText().getOrigin().y + offset.y);
}

void LevelIndicator::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

void LevelIndicator::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Sprite::draw(target, states);
	
	target.draw(getText());
}




