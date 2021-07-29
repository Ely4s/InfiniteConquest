//
// Created by Elyas EL IDRISSI on 05/04/2021.
//

#include "GameOver.h"
#include "Global/GlobalGame.h"
#include "Utils/DebugRect.h"

GameOver::GameOver() : Sprite(tm.get("game_over"), {354, 344}, {0, 0, 354, 344})
{
	setOrigin(getSize().x/2.f, getSize().y/2.f);
	
	for (auto & text : getTexts())
	{
		text.setFont(fm.get("ice_pixel-7"));
		text.setAlign(Text::CENTER, Text::MIDDLE);
	}
	
	auto text = getTexts().begin();
	
	text->setCharacterSize(50);
	text->setString("Game Over");
	text->setFillColor(sf::Color::Red);
	text->setPosition(169, 36);
	
	text++;
	
	text->setCharacterSize(30);
	text->setString("Score :");
	text->setPosition(169, 100 + 10);
	
	text++;
	
	text->setCharacterSize(30);
	text->setString("Meilleur score :");
	text->setPosition(169, 128 + 20);
	
	text++;
	
	text->setCharacterSize(40);
	text->setString("Continuer");
	text->setFillColor(sf::Color::Green);
	text->setPosition(169, 224);
	
	text++;
	
	text->setCharacterSize(40);
	text->setString("Quitter");
	text->setFillColor(sf::Color::Red);
	text->setPosition(169, 224 + 82);
	
	int it = 0;
	for (auto & colidBox : getColidBoxs())
	{
		colidBox.left = 10 - getOrigin().x;
		colidBox.top = 194 - getOrigin().y + (float)(it * 82);
		colidBox.width = 318;
		colidBox.height = 58;
		
		it++;
	}
}

void GameOver::refresh(unsigned int score, unsigned int bestScore)
{
	std::string bestScoreStr;
	
	if (score > bestScore)
	{
		bestScoreStr += "New Highscore : " + std::to_string(score);
		getTexts().at(2).setFillColor(sf::Color::Green);
	}
	else
	{
		bestScoreStr += "Highscore : " + std::to_string(bestScore);
		getTexts().at(2).setFillColor(sf::Color::White);
	}
	
	getTexts().at(1).setString("Score : " + std::to_string(score));
	getTexts().at(2).setString(bestScoreStr);
};

int GameOver::checkChoice()
{
	if (game.getEvent().hasEventTypeAs(sf::Event::MouseButtonPressed))
	{
		sf::Vector2f mousePos = game.getWindow().mapPixelToCoords(sf::Mouse::getPosition(game.getWindow()));
		
		int it = 0;
		for (auto & colidBox : getColidBoxs())
		{
			if (colidBox.contains(mousePos))
			{
				return it+1;
			}
			
			it++;
		}
	}
	
	return false;
}

std::vector<Text> &GameOver::getTexts()
{
	return texts;
}

const std::vector<Text> &GameOver::getTexts() const
{
	return texts;
}

void GameOver::setTexts(const std::vector<Text> &texts)
{
	GameOver::texts = texts;
}

std::vector<sf::FloatRect> &GameOver::getColidBoxs()
{
	return colidBoxs;
}

const std::vector<sf::FloatRect> &GameOver::getColidBoxs() const
{
	return colidBoxs;
}

void GameOver::setColidBoxs(const std::vector<sf::FloatRect> &colidBoxs)
{
	GameOver::colidBoxs = colidBoxs;
}

void GameOver::setPosition(float x, float y)
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

void GameOver::setPosition(const sf::Vector2f &position)
{
	setPosition(position.x, position.y);
}

void GameOver::setOrigin(float x, float y)
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

void GameOver::setOrigin(const sf::Vector2f &origin)
{
	setOrigin(origin.x, origin.y);
}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Sprite::draw(target, states);
	
	for (auto & text : getTexts())
	{
		target.draw(text);
	}
}
