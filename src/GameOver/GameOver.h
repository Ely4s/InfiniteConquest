//
// Created by Elyas EL IDRISSI on 05/04/2021.
//

#ifndef INFINITECONQUEST_GAMEOVER_H
#define INFINITECONQUEST_GAMEOVER_H

#include "Sprite/Sprite.h"
#include "Text/Text.h"
#include "Global/GlobalFontManager.h"
#include "Global/GlobalTextureManager.h"

class GameOver : public Sprite
{

public:

	GameOver();
	
	int checkChoice();
	void refresh(unsigned int score, unsigned int bestScore);
	
	std::vector<Text> &getTexts();
	const std::vector<Text> &getTexts() const;
	void setTexts(const std::vector<Text> &texts);
	
	std::vector<sf::FloatRect> &getColidBoxs();
	const std::vector<sf::FloatRect> &getColidBoxs() const;
	void setColidBoxs(const std::vector<sf::FloatRect> &colidBoxs);
	
	void setPosition(float x, float y) override;
	
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	
	void setOrigin(const sf::Vector2f &origin) override;

protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	
	std::vector<Text> texts = std::vector<Text>(5, Text());
	std::vector<sf::FloatRect> colidBoxs = std::vector<sf::FloatRect>(2, sf::FloatRect());
	
};


#endif //INFINITECONQUEST_GAMEOVER_H
