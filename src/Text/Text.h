//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#ifndef INFINITECONQUEST_TEXT_H
#define INFINITECONQUEST_TEXT_H

#include <SFML/Graphics.hpp>
#include "Text/Font.h"
#include "Interface/Transformable.h"
#include "Interface/Drawable.h"

class Text : public Transformable, public Drawable
{

public:
	
	enum ALIGN_X{LEFT, RIGHT, CENTER};
	enum ALIGN_Y{TOP, BOTTOM, MIDDLE};
	
	Text();
	Text(const std::string &str, const Font &font, unsigned int fontSize);
	
	virtual const sf::String &getString() const;
	virtual void setString(const sf::String &string);
	
	virtual const sf::Font *getFont() const;
	virtual void setFont(const sf::Font &font);
	
	virtual unsigned int getCharacterSize() const;
	virtual void setCharacterSize(unsigned int size);
	
	virtual float getLetterSpacing() const;
	virtual void setLineSpacing(float spacingFactor);
	
	virtual float getLineSpacing() const;
	virtual void setLetterSpacing(float spacingFactor);
	
	virtual sf::Uint32 getStyle() const;
	virtual void setStyle(sf::Uint32 style);
	
	virtual const sf::Color &getFillColor() const;
	virtual void setFillColor(const sf::Color &color);
	
	virtual const sf::Color &getOutlineColor() const;
	virtual void setOutlineColor(const sf::Color &color);
	
	virtual float getOutlineThickness() const;
	virtual void setOutlineThickness(float thickness);
	
	virtual sf::Vector2f findCharacterPos(std::size_t index) const;
	
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;
	
	const sf::Vector2f &getPosition() const override;
	void setPosition(float x, float y) override;
	void setPosition(const sf::Vector2f &position) override;
	
	sf::Vector2f getTopLeft() const override;
	
	void setRotation(float angle) override;
	float getRotation() const override;
	
	const sf::Vector2f &getOrigin() const override;
	void setOrigin(float x, float y) override;
	void setOrigin(const sf::Vector2f &origin) override;

	Text::ALIGN_X getAlignX();
	Text::ALIGN_Y getAlignY();
	void setAlign(ALIGN_X x, ALIGN_Y y);
	void setAlignX(ALIGN_X x);
	void setAlignY(ALIGN_Y y);
	
	void fontOffsetUpdate();
	sf::Vector2f getFontOffset() const;
	
protected:
	
	const sf::Vector2f &getSize() const override;
	void setSize(float w, float h) override;
	void setSize(const sf::Vector2f &size) override;
	void scaleSize(float w, float h) override;
	void scaleSize(const sf::Vector2f &size) override;
	
	void flipOrigin() override;
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	
private:
	
	sf::Text text;
	
	ALIGN_X alignX = LEFT;
	ALIGN_Y alignY = TOP;
	
	sf::Vector2f origin;
	sf::Vector2f fontOrigin;
	sf::Vector2f sideOrigin;
	
};


#endif //INFINITECONQUEST_TEXT_H
