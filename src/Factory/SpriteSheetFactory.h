//
// Created by Elyas EL IDRISSI on 29/03/2021.
//

#ifndef INFINITECONQUEST_SPRITESHEETFACTORY_H
#define INFINITECONQUEST_SPRITESHEETFACTORY_H

#include "Factory.h"
#include "Sprite/SpriteSheet.h"
#include "Global/GlobalTextureManager.h"
#include "Entity/EntityState.h"

class SpriteSheetFactory : public Factory<SpriteSheet>
{

public:
	
	SpriteSheetFactory(){init();};
	
	void init() override
	{
		SpriteSheet s;
		std::string entityName;
		
		//-------------------------------- RogueMan --------------------------------//
		
		entityName = "RogueMan";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(300, 300), sf::IntRect (0, 0, 100, 100), 0.07f));
			s.setOrigin(135, 245);
			add(entityName+"_"+states.second, s);
		}
		
		entityName = "Snow Chaser";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(80*3, 80*3), sf::IntRect (0, 0, 80, 80), 0.07f));
			s.setOrigin(43*3, 63*3);
			add(entityName+"_"+states.second, s);
		}
		
		entityName = "Spectral Revenant";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(80*3, 80*3), sf::IntRect (0, 0, 80, 80), 0.07f));
			s.setOrigin(37*3, 67*3);
			add(entityName+"_"+states.second, s);
		}
		
		entityName = "Death Knell";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(120*3, 120*3), sf::IntRect (0, 0, 120, 120), 0.07f));
			s.setOrigin(59*3, 103*3);
			add(entityName+"_"+states.second, s);
		}
		
		entityName = "Vorpal Reaver";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(80*3, 80*3), sf::IntRect (0, 0, 80, 80), 0.07f));
			s.setOrigin(34*3, 63*3);
			add(entityName+"_"+states.second, s);
		}
		
		entityName = "Grandmaster Variax";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(120*3, 120*3), sf::IntRect (0, 0, 120, 120), 0.07f));
			s.setOrigin(63*3, 103*3);
			add(entityName+"_"+states.second, s);
		}
		
		entityName = "Stygian Observer";
		for (const auto& states : EntityState::STATES_LABEL)
		{
			s = SpriteSheet(SpriteSheet(tm.get(entityName+"_"+states.second), sf::Vector2f(130*3, 130*3), sf::IntRect (0, 0, 130, 130), 0.07f));
			s.setOrigin(64*3, 113*3);
			add(entityName+"_"+states.second, s);
		}
		
	};
	
};


#endif //INFINITECONQUEST_SPRITESHEETFACTORY_H
