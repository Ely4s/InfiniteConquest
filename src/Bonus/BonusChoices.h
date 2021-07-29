//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#ifndef INFINITECONQUEST_BONUSCHOICES_H
#define INFINITECONQUEST_BONUSCHOICES_H

#include "Sprite/Sprite.h"
#include "Text/Text.h"
#include "EntityBonus.h"
#include <SFML/Graphics.hpp>

class BonusChoices : public Sprite
{

public:
	
	BonusChoices();
	~BonusChoices();
	
	void shuffle();
	bool checkChoice();
	
	std::vector<sf::FloatRect> &getColidBoxs();
	void setColidBoxs(const std::vector<sf::FloatRect> &colidBoxs);
	
	const std::vector<Text> &getTexts() const;
	std::vector<Text> &getTexts();
	void setTexts(const std::vector<Text> &texts);
	
	std::vector<EntityBonus *> &getAllBonus();
	void setAllBonus(const std::vector<EntityBonus *> &allBonus);
	
	void setPosition(float x, float y) override;
	
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	
	void setOrigin(const sf::Vector2f &origin) override;


protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	
	std::vector<sf::FloatRect> colidBoxs = std::vector<sf::FloatRect>(3, sf::FloatRect());
	std::vector<Text> texts = std::vector<Text>(4, Text());
	std::vector<EntityBonus*> allBonus;
};


#endif //INFINITECONQUEST_BONUSCHOICES_H
