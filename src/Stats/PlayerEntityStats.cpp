//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#include <iostream>
#include "PlayerEntityStats.h"
#include "Global/GlobalTextureManager.h"
#include "Global/GlobalFontManager.h"

PlayerEntityStats::PlayerEntityStats() : EntityStats<PlayerEntity>(tm.get("player_stats"), sf::Vector2f(316, 100))
{
	getLifeGauge().setPosition(getPosition().x + 16, getPosition().y + 8);
	getRageGauge().setPosition(getPosition().x + 16, getPosition().y + 28);

	getLifeText().setFont(fm.get("ice_pixel-7"));
	getLifeText().setCharacterSize(25);
	getLifeText().setAlign(Text::CENTER, Text::MIDDLE);
	getLifeText().setPosition({getPosition().x+212 + 62*0, getPosition().y + 24});

	getLifeMaxText().setFont(fm.get("ice_pixel-7"));
	getLifeMaxText().setCharacterSize(25);
	getLifeMaxText().setAlign(Text::CENTER, Text::MIDDLE);
	getLifeMaxText().setPosition({getPosition().x+212 + 62*1, getPosition().y + 24});

	getFamiliarAttackText().setFont(fm.get("ice_pixel-7"));
	getFamiliarAttackText().setCharacterSize(25);
	getFamiliarAttackText().setAlign(Text::CENTER, Text::MIDDLE);
	getFamiliarAttackText().setPosition({getPosition().x+44 + 74*0, getPosition().y + 77});

	getAttackText().setFont(fm.get("ice_pixel-7"));
	getAttackText().setCharacterSize(25);
	getAttackText().setAlign(Text::CENTER, Text::MIDDLE);
	getAttackText().setPosition({getPosition().x+44 + 74*1, getPosition().y + 77});

	getRageText().setFont(fm.get("ice_pixel-7"));
	getRageText().setCharacterSize(25);
	getRageText().setAlign(Text::CENTER, Text::MIDDLE);
	getRageText().setPosition({getPosition().x+44 + 74*2, getPosition().y + 77});
}

PlayerEntityStats::PlayerEntityStats(PlayerEntity * playerTarget, FamiliarEntity * familiarTarget) : PlayerEntityStats()
{
	setTarget(playerTarget);
	setFamiliarTarget(familiarTarget);
}

RageGauge &PlayerEntityStats::getRageGauge()
{
	return rageGauge;
}

const RageGauge &PlayerEntityStats::getRageGauge() const
{
	return rageGauge;
}

void PlayerEntityStats::setRageGauge(const RageGauge &rageGauge)
{
	PlayerEntityStats::rageGauge = rageGauge;
}

Text &PlayerEntityStats::getFamiliarAttackText()
{
	return familiarAttackText;
}

const Text &PlayerEntityStats::getFamiliarAttackText() const
{
	return familiarAttackText;
}

void PlayerEntityStats::setFamiliarAttackText(const Text &familiarAttackText)
{
	PlayerEntityStats::familiarAttackText = familiarAttackText;
}

Text &PlayerEntityStats::getRageText()
{
	return playerRageText;
}

const Text &PlayerEntityStats::getRageText() const
{
	return playerRageText;
}

void PlayerEntityStats::setRageText(const Text &playerRageText)
{
	PlayerEntityStats::playerRageText = playerRageText;
}

void PlayerEntityStats::setTarget(PlayerEntity * entityTarget)
{
	EntityStats::setTarget(entityTarget);
	
	getRageGauge().setTarget(*entityTarget);
	rageGaugeRefresh();
	
	rageTextRefresh();
}

FamiliarEntity *PlayerEntityStats::getFamiliarTarget() const
{
	return familiarTarget;
};

void PlayerEntityStats::setFamiliarTarget(FamiliarEntity * familiarTarget)
{
	PlayerEntityStats::familiarTarget = familiarTarget;
	
	familiarAttackTextRefresh();
};

void PlayerEntityStats::refresh()
{
	(getTarget()) ? setTarget(getTarget()) : void();
	(getFamiliarTarget()) ? setFamiliarTarget(getFamiliarTarget()) : void();
}

void PlayerEntityStats::rageGaugeRefresh()
{
	getRageGauge().refresh();
};

void PlayerEntityStats::familiarAttackTextRefresh()
{
	getFamiliarAttackText().setString(std::to_string(getFamiliarTarget()->getAttackDamage()));
};

void PlayerEntityStats::rageTextRefresh()
{
	int a = getTarget()->getRageDamage();
	getRageText().setString(std::to_string(a));
};

void PlayerEntityStats::setPosition(float x, float y)
{
	sf::Vector2f offset = {x - getPosition().x, y - getPosition().y};
	EntityStats::setPosition(x, y);
	
	getRageGauge().move(offset.x, offset.y);
	getRageText().move(offset.x, offset.y);
	getFamiliarAttackText().move(offset.x, offset.y);
}

void PlayerEntityStats::setPosition(const sf::Vector2f &position)
{
	PlayerEntityStats::setPosition(position.x, position.y);
}

void PlayerEntityStats::setOrigin(float x, float y)
{
	sf::Vector2f offset = {x - getOrigin().x, y - getOrigin().y};
	EntityStats::setOrigin(x, y);
	
	getRageGauge().setOrigin(getRageGauge().getOrigin().x + offset.x, getRageGauge().getOrigin().y + offset.y);
	getRageText().setOrigin(getRageText().getOrigin().x + offset.x, getRageText().getOrigin().y + offset.y);
	getFamiliarAttackText().setOrigin(getFamiliarAttackText().getOrigin().x + offset.x, getFamiliarAttackText().getOrigin().y + offset.y);
}

void PlayerEntityStats::setOrigin(const sf::Vector2f &origin)
{
	PlayerEntityStats::setOrigin(origin.x, origin.y);
}

void PlayerEntityStats::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	EntityStats::draw(target, states);
	
	target.draw(getRageGauge());
	target.draw(getFamiliarAttackText());
	target.draw(getRageText());
}

