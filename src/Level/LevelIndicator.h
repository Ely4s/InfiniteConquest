//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_LEVELINDICATOR_H
#define INFINITECONQUEST_LEVELINDICATOR_H

#include "Sprite/Sprite.h"
#include "Text/Text.h"

class LevelIndicator : public Sprite
{

public:

	LevelIndicator();
	LevelIndicator(unsigned int level);
	
	void refresh();
	void nextLevel();
	void resetLevel();
	
	Text &getText();
	const Text &getText() const;
	void setText(const Text &text);
	
	unsigned int getLevel() const;
	void setLevel(unsigned int level);
	
	void setPosition(float x, float y) override;
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	void setOrigin(const sf::Vector2f &origin) override;

protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	
	Text text;
	unsigned int level = 1;

};


#endif //INFINITECONQUEST_LEVELINDICATOR_H
