//
// Created by Elyas EL IDRISSI on 06/03/2021.
//

#ifndef INFINITECONQUEST_TEXTUREMANAGER_H
#define INFINITECONQUEST_TEXTUREMANAGER_H

#include "Manager.h"
#include <SFML/Graphics.hpp>
#include "Sprite/Texture.h"
#include "Entity/EntityState.h"

class TextureManager : public Manager<Texture>
{

public :
	
	TextureManager(){init();}
	
	void init() override
	{
	
		add("RogueMan_idle", Texture("content/Player/RogueMan/RogueMan_idle.png"));
		add("RogueMan_run", Texture("content/Player/RogueMan/RogueMan_run.png"));
		add("RogueMan_attack", Texture("content/Player/RogueMan/RogueMan_attack.png"));
		add("RogueMan_death", Texture("content/Player/RogueMan/RogueMan_death.png"));
		
		add("Snow Chaser_idle", Texture("content/Familiar/Snow Chaser/Snow Chaser_idle.png"));
		add("Snow Chaser_run", Texture("content/Familiar/Snow Chaser/Snow Chaser_run.png"));
		add("Snow Chaser_attack", Texture("content/Familiar/Snow Chaser/Snow Chaser_attack.png"));
		add("Snow Chaser_death", Texture("content/Familiar/Snow Chaser/Snow Chaser_death.png"));
		
		add("player_stats", Texture("content/Stats/player_stats.png"));
		add("enemy_stats", Texture("content/Stats/enemy_stats.png"));
		add("gauge_life", Texture("content/Stats/gauge.png"));
		
		add("qte_bar", Texture("content/Qte/qte_bar.png"));
		add("qte_block_player", Texture("content/Qte/qte_block_player.png"));
		add("qte_block_enemy", Texture("content/Qte/qte_block_enemy.png"));
		add("qte_cursor", Texture("content/Qte/qte_cursor.png"));
		
		add("bonus", Texture("content/Bonus/bonus.png"));
		add("level_indicator", Texture("content/Level/level_indicator.png"));
		add("game_over", Texture("content/GameOver/game_over.png"));
		
		add("plateform", Texture("content/Background/plateform.png"));
		add("background", Texture("content/Background/background.png"));
		
		
		std::vector<std::string> enemiesId =
		{
				"Spectral Revenant",
				"Death Knell",
				"Vorpal Reaver",
				"Grandmaster Variax",
				"Stygian Observer",
//				"Klaxon",
//				"Arcane Devourer",
//				"Underlord Xor'Xuul",
//				"Carrion Collector",
//				"Blood Baronette"
		};
		
		for(auto & enemyId : enemiesId)
		{
			for (const auto& state : EntityState::STATES_LABEL)
			{
				add(enemyId+"_"+state.second, Texture("content/Enemies/"+enemyId+"/"+enemyId+"_"+state.second+".png"));
			}
		}
		
		setDefault();
	}
	
	void setDefault() override
	{
		sf::RenderTexture errorTexture;
		errorTexture.create(2, 2);
		sf::RectangleShape blackRect(sf::Vector2f(1, 1));
		blackRect.setFillColor(sf::Color::Black);
		errorTexture.clear(sf::Color::Magenta);
		errorTexture.draw(blackRect);
		blackRect.setPosition(1, 1);
		errorTexture.draw(blackRect);
		errorTexture.display();
		
		Texture & texture = (Texture&)errorTexture.getTexture();
		
		add(ERROR_RESOURCE_NAME, texture);
	}

private:

};


#endif //INFINITECONQUEST_TEXTUREMANAGER_H
