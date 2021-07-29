//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#include "Text.h"

#include <iostream>
#include <math.h>
#include "Utils/DebugRect.h"

Text::Text() : Transformable(), Drawable()
{

}

Text::Text(const std::string &str, const Font &font, unsigned int fontSize) : Text()
{

}

const sf::String &Text::getString() const
{
	return text.getString();
}

void Text::setString(const sf::String &string)
{
	text.setString(string);
	fontOffsetUpdate();
}

const sf::Font *Text::getFont() const
{
	return text.getFont();
}

void Text::setFont(const sf::Font &font)
{
	text.setFont(font);
	fontOffsetUpdate();
}

unsigned int Text::getCharacterSize() const
{
	return text.getCharacterSize();
}

void Text::setCharacterSize(unsigned int size)
{
	text.setCharacterSize(size);
	fontOffsetUpdate();
}

float Text::getLineSpacing() const
{
	return text.getLineSpacing();
}

void Text::setLineSpacing(float spacingFactor)
{
	text.setLineSpacing(spacingFactor);
}

float Text::getLetterSpacing() const
{
	return text.getLetterSpacing();
}

void Text::setLetterSpacing(float spacingFactor)
{
	text.setLetterSpacing(spacingFactor);
}

sf::Uint32 Text::getStyle() const
{
	return text.getStyle();
}

void Text::setStyle(sf::Uint32 style)
{
	text.setStyle(style);
}

const sf::Color &Text::getFillColor() const
{
	return text.getFillColor();
}

void Text::setFillColor(const sf::Color &color)
{
	text.setFillColor(color);
}

const sf::Color &Text::getOutlineColor() const
{
	return text.getOutlineColor();
}

void Text::setOutlineColor(const sf::Color &color)
{
	text.setOutlineColor(color);
}

float Text::getOutlineThickness() const
{
	return text.getOutlineThickness();
}

void Text::setOutlineThickness(float thickness)
{
	text.setOutlineThickness(thickness);
}

sf::Vector2f Text::findCharacterPos(std::size_t index) const
{
	return text.findCharacterPos(index);
}

sf::FloatRect Text::getLocalBounds() const
{
	return text.getLocalBounds();
}

sf::FloatRect Text::getGlobalBounds() const
{
	return text.getGlobalBounds();
}

const sf::Vector2f &Text::getPosition() const
{
	return text.getPosition();
}

void Text::setPosition(float x, float y)
{
	text.setPosition(x, y);
	fontOffsetUpdate();
}

void Text::setPosition(const sf::Vector2f &position)
{
	setPosition(position.x, position.y);
}

sf::Vector2f Text::getTopLeft() const
{
	return Transformable::getTopLeft();
}

const sf::Vector2f &Text::getSize() const
{
	return Transformable::getSize();
}

void Text::setSize(float w, float h)
{
	Transformable::setSize(w, h);
}

void Text::setSize(const sf::Vector2f &size)
{
	Transformable::setSize(size);
}

void Text::scaleSize(float w, float h)
{
	Transformable::scaleSize(w, h);
}

void Text::scaleSize(const sf::Vector2f &size)
{
	Transformable::scaleSize(size);
}

void Text::setRotation(float angle)
{
	text.setRotation(angle);
}

float Text::getRotation() const
{
	return text.getRotation();
}

const sf::Vector2f &Text::getOrigin() const
{
	return origin;
}

void Text::setOrigin(float x, float y)
{
	origin = {x, y};
	text.setOrigin(origin.x + fontOrigin.x + sideOrigin.x, origin.y + fontOrigin.y + sideOrigin.y);
}

void Text::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

Text::ALIGN_X Text::getAlignX()
{
	return alignX;
};

Text::ALIGN_Y Text::getAlignY()
{
	return alignY;
};

void Text::setAlign(ALIGN_X x, ALIGN_Y y)
{
	setAlignX(x);
	setAlignY(y);
};

void Text::setAlignX(ALIGN_X x)
{
	alignX = x;
	sideOrigin = {(x == LEFT) ? 0 : (x == CENTER) ? (float) getGlobalBounds().width / 2.f : (x == RIGHT) ? getGlobalBounds().width : sideOrigin.x, sideOrigin.y};
	setOrigin(getOrigin());
};

void Text::setAlignY(ALIGN_Y y)
{
	alignY = y;
	sideOrigin = {sideOrigin.x, (y == TOP) ? 0 : (y == MIDDLE) ? (float) getGlobalBounds().height / 2.f : (y == BOTTOM) ? getGlobalBounds().height : sideOrigin.y};
	setOrigin(getOrigin());
}

void Text::fontOffsetUpdate()
{
	fontOrigin = getFontOffset();
	setAlign(getAlignX(), getAlignY());
	setOrigin(getOrigin());
};


sf::Vector2f Text::getFontOffset() const
{
	const sf::Font * fontSave = getFont();
	unsigned int sizeSave = getCharacterSize();
	std::string stringSave = getString();
	
	std::atomic<sf::Text*> t;
	t.store(new sf::Text());
	
	if (getFont())t.load()->setFont(*fontSave);
	t.load()->setCharacterSize(sizeSave);
	t.load()->setString(stringSave);
	
	sf::Vector2f offset = {t.load()->getTransform().transformRect(t.load()->getLocalBounds()).left, t.load()->getTransform().transformRect(t.load()->getLocalBounds()).top};
	
	delete t;
	
	return offset;
}

void Text::flipOrigin()
{
	Transformable::flipOrigin();
}

void Text::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(text);
}
