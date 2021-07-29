//
// Created by Elyas EL IDRISSI on 03/04/2021.
//

#include "EnemyEntityStats.h"

#include "Global/GlobalTextureManager.h"
#include "Global/GlobalFontManager.h"

EnemyEntityStats::EnemyEntityStats() : EntityStats<Entity>(tm.get("enemy_stats"), sf::Vector2f(316, 100))
{
	getLifeGauge().setPosition(getTopLeft().x + 300, getPosition().y + 8);
	getLifeGauge().flip();
	
	getLifeText().setFont(fm.get("ice_pixel-7"));
	getLifeText().setCharacterSize(25);
	getLifeText().setAlign(Text::CENTER, Text::MIDDLE);
	getLifeText().setPosition({getTopLeft().x + 42 + 62*0, getTopLeft().y + 24});
	
	getLifeMaxText().setFont(fm.get("ice_pixel-7"));
	getLifeMaxText().setCharacterSize(25);
	getLifeMaxText().setAlign(Text::CENTER, Text::MIDDLE);
	getLifeMaxText().setPosition({getTopLeft().x + 42 + 62*1, getTopLeft().y + 24});
	
	getAttackText().setFont(fm.get("ice_pixel-7"));
	getAttackText().setCharacterSize(25);
	getAttackText().setAlign(Text::CENTER, Text::MIDDLE);
	getAttackText().setPosition({getTopLeft().x + 272, getTopLeft().y + 76});
}

EnemyEntityStats::EnemyEntityStats(Entity * enemyTarget) : EnemyEntityStats()
{
	setTarget(enemyTarget);
}

void EnemyEntityStats::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	EntityStats::draw(target, states);
}
