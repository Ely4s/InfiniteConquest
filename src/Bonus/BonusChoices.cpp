//
// Created by Elyas EL IDRISSI on 04/04/2021.
//

#include "BonusChoices.h"

#include <algorithm>
#include <random>

#include "PlayerEntityAttackIncrease.h"
#include "PlayerEntityRageIncrease.h"
#include "PlayerEntityLifeRegeneration.h"
#include "PlayerEntityLifeMaxIncrease.h"
#include "FamiliarEntityAttackIncrease.h"
#include "Global/GlobalFontManager.h"
#include "Global/GlobalTextureManager.h"
#include "Global/GlobalGame.h"
#include "Utils/DebugRect.h"

BonusChoices::BonusChoices() :  Sprite(tm.get("bonus"), {354, 318})
{
	setOrigin(getSize().x/2.f, getSize().y/2.f);
	
	getAllBonus().push_back(new PlayerEntityAttackIncrease());
	getAllBonus().push_back(new PlayerEntityRageIncrease());
	getAllBonus().push_back(new PlayerEntityLifeMaxIncrease());
	getAllBonus().push_back(new PlayerEntityLifeRegeneration());
	getAllBonus().push_back(new FamiliarEntityAttackIncrease());

	int it = 0;
	for (auto & text : getTexts())
	{
		text.setFont(fm.get("ice_pixel-7"));
		text.setAlign(Text::CENTER, Text::MIDDLE);
		
		if (it == 0)
		{
			text.setCharacterSize(50);
			text.setPosition(169, 36);
			text.setFillColor(sf::Color::Green);
			text.setString("Choix du bonus");
		}
		else
		{
			text.setCharacterSize(30);
			text.setPosition(169, (float)(115 + (82*(it-1))));
		}
		
		it++;
	}
	
	it = 0;
	for (auto & colidBox : getColidBoxs())
	{
		
		colidBox.left = 10 - getOrigin().x;
		colidBox.top = (float)(86 - getOrigin().y + (float)(82*(it)));
		colidBox.width = 318;
		colidBox.height = 58;
		
		it++;
	}
	
	shuffle();
}

BonusChoices::~BonusChoices()
{
	for(auto * bonus : getAllBonus())
	{
		delete bonus;
	}
}

void BonusChoices::shuffle()
{
	std::default_random_engine rng(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(std::begin(getAllBonus()), std::end(getAllBonus()), rng);
	
	int it = 0;
	for (auto text = getTexts().begin() + 1; text != getTexts().end(); ++text)
	{
		text->setString(getAllBonus().at(it)->getLabel());
		it++;
	}
};

std::vector<sf::FloatRect> &BonusChoices::getColidBoxs()
{
	return colidBoxs;
}

void BonusChoices::setColidBoxs(const std::vector<sf::FloatRect> &colidBoxs)
{
	BonusChoices::colidBoxs = colidBoxs;
}

std::vector<Text> &BonusChoices::getTexts()
{
	return texts;
}

const std::vector<Text> &BonusChoices::getTexts() const
{
	return texts;
}

void BonusChoices::setTexts(const std::vector<Text> &texts)
{
	BonusChoices::texts = texts;
}

std::vector<EntityBonus *> &BonusChoices::getAllBonus()
{
	return allBonus;
}

void BonusChoices::setAllBonus(const std::vector<EntityBonus *> &allBonus)
{
	BonusChoices::allBonus = allBonus;
}

bool BonusChoices::checkChoice()
{
	if (game.getEvent().hasEventTypeAs(sf::Event::MouseButtonPressed))
	{
		sf::Vector2f mousePos = game.getWindow().mapPixelToCoords(sf::Mouse::getPosition(game.getWindow()));
		
		int it = 0;
		for (auto & colidBox : getColidBoxs())
		{
			if (colidBox.contains(mousePos))
			{
				return (getAllBonus().at(it)->apply(&game.getPlayerEntity()) || getAllBonus().at(it)->apply(&game.getFamiliarEntity()));
			}
			
			it++;
		}
	}
	
	return false;
}

void BonusChoices::setPosition(float x, float y)
{
	sf::Vector2f offset = {x - getPosition().x, y - getPosition().y};
	Sprite::setPosition(x, y);
	
	for (auto & text : getTexts())
	{
		text.move(offset.x, offset.y);
	}
	
	for (auto & colidBox : getColidBoxs())
	{
		colidBox.left += offset.x;
		colidBox.top += offset.y;
	}
}

void BonusChoices::setPosition(const sf::Vector2f &position)
{
	setPosition(position.x, position.y);
}

void BonusChoices::setOrigin(float x, float y)
{
	sf::Vector2f offset = {x - getOrigin().x, y - getOrigin().y};
	Sprite::setOrigin(x, y);
	
	for (auto & text : getTexts())
	{
		text.setOrigin(text.getOrigin().x + offset.x, text.getOrigin().y +offset.y);
	}
	
	for (auto & colidBox : getColidBoxs())
	{
		colidBox.left -= offset.x;
		colidBox.top -= offset.y;
	}
}

void BonusChoices::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

void BonusChoices::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Sprite::draw(target, states);
	
	for (auto & text : getTexts())
	{
		target.draw(text);
	}
}