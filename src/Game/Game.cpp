//
// Created by Elyas EL IDRISSI on 12/03/2021.
//

#include "Game.h"

#include <unistd.h>
#include <iostream>
#include <iostream>
#include <fstream>

#include "Global/GlobalPlayerEntityFactory.h"
#include "Global/GlobalEnemyEntityFactory.h"
#include "Global/GlobalFamiliarEntityFactory.h"

#include "Qte/QtePlayerBlock.h"

#include "Bonus/PlayerEntityLifeRegeneration.h"
#include "Bonus/PlayerEntityLifeMaxIncrease.h"
#include "Bonus/BonusChoices.h"
#include "Level/EnemyEntityLeveling.h"
#include "Utils/DebugRect.h"

Game::Game()
{
	init();
}

void Game::loadSave()
{
	std::ifstream infile("content/Save/save.txt");

	int bestScore = 0;
	
  	if (infile.good())
  	{
		std::string sLine;
		getline(infile, sLine);
		
		int bestScore = 0;
		
		try {bestScore = std::atoi(sLine.c_str());}
		catch(std::exception const & e){}
		
		setBestScore(bestScore);
	}
  	else
	{
  		setBestScore(bestScore);
	}
};

void Game::init()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	
	getWindow().create(sf::VideoMode(1440, 900, 32), "Infinite Conquest", sf::Style::Default, settings); setFps(60);
	getWindow().setActive(true);
	getWindow().setView(View(sf::FloatRect(0,0, floor(720), floor(450))));
	
	loadSave();
	
	setEntitySpeed(6);
	getPlateform().setSpeed(getEntitySpeed());
	
	getPlayerEntityStats().setPosition(getWindow().getView().getTopLeft().x, getWindow().getView().getTopLeft().y + 4);
	getEnemyEntityStats().setPosition(getWindow().getView().getTopLeft().x + getWindow().getView().getSize().x - getEnemyEntityStats().getSize().x, getWindow().getView().getTopLeft().y + 4);
	getQte().setPosition(getWindow().getView().getSize().x/2.f, getWindow().getView().getSize().y - 70);
	getBonus().setPosition(getWindow().getView().getTopLeft().x + getWindow().getView().getSize().x/2.f, getWindow().getView().getTopLeft().y + getWindow().getView().getSize().y/2.f);
	getLevelIndicator().setPosition(getWindow().getView().getTopLeft().x + getWindow().getView().getSize().x/2.f, 0);
	getGameOver().setPosition(getWindow().getView().getTopLeft().x + getWindow().getView().getSize().x/2.f, getWindow().getView().getTopLeft().y + getWindow().getView().getSize().y/2.f);
	getPlateform().setPosition(0, getWindow().getView().getTopLeft().y + getWindow().getView().getSize().y - getPlateform().getSize().y);
	getTags().add(GameTags::INIT);
}

void Game::update()
{
	getChrono().start();
	
	getEvent().resetEvents(getWindow());
	
	if (getEvent().hasEventTypeAs(sf::Event::Closed))
	{
		getWindow().close();
	}
	
	if (getTags().contains(GameTags::INIT))
	{
		initPhase();
	}
	
	if (getTags().contains(GameTags::START))
	{
		startPhase();
	}

	if (getTags().contains(GameTags::FIGHT))
	{
		fightPhase();
	}

	if (getTags().contains(GameTags::BONUS))
	{
		bonusPhase();
	}
	
	if (getTags().contains(GameTags::REINIT))
	{
		reinitPhase();
	}
	
	if (getTags().contains(GameTags::GAMEOVER))
	{
		gameOverPhase();
	}
	
	if ( ! (getPlayerEntity().getSprite().isAtLastStep() && getPlayerEntity().getState() == Entity::State::DEATH) )
	{
		getPlayerEntity().getSprite().goToNextStep();
	}
	if ( ! (getEnemyEntity().getSprite().isAtLastStep() && getEnemyEntity().getState() == Entity::State::DEATH) )
	{
		getEnemyEntity().getSprite().goToNextStep();
	}
	if ( ! (getFamiliarEntity().getSprite().isAtLastStep() && getFamiliarEntity().getState() == Entity::State::DEATH) )
	{
		getFamiliarEntity().getSprite().goToNextStep();
	}
}

void Game::initPhase()
{
	getLevelIndicator().resetLevel();
	
	setPlayerEntity(pef.getCopy("RogueMan"));
	getPlayerEntity().setState(Entity::State::RUN);
	
	setEnemyEntity(getRandomEnemyEntity());
	getEnemyEntity().setState(Entity::State::RUN);
	
	setFamiliarEntity(fef.getCopy("Snow Chaser"));
	getFamiliarEntity().setState(Entity::State::RUN);

	getPlayerEntityStats().setTarget(&getPlayerEntity());
	getPlayerEntityStats().setFamiliarTarget(&getFamiliarEntity());
	getEnemyEntityStats().setTarget(&getEnemyEntity());
	
	getPlayerEntity().setPosition(getPlayerEntitySpawnPos());
	getEnemyEntity().setPosition(getEnemyEntitySpawnPos());
	getFamiliarEntity().setPosition(getFamiliarEntitySpawnPos());
	
	getTags().remove(GameTags::INIT);
	getTags().add(GameTags::START);
};

void Game::startPhase()
{
	int inited = 0;
	
	if (getPlayerEntity().getPosition().x < getPlayerEntityFightPos().x)
	{
		getPlayerEntity().move(getEntitySpeed(), 0);
		
		if (getPlayerEntity().getPosition().x > getPlayerEntityFightPos().x)
		{
			getPlayerEntity().setPosition(getPlayerEntityFightPos());
		}
		
		if (getPlayerEntity().getPosition() == getPlayerEntityFightPos())
		{
			getPlayerEntity().idle();
			inited++;
		}
	}
	else
	{
		inited++;
	}
	
	if (getFamiliarEntity().getPosition().x < getFamiliarEntityFightPos().x)
	{
		getFamiliarEntity().move(getEntitySpeed(), 0);
		
		if (getFamiliarEntity().getPosition().x > getFamiliarEntityFightPos().x)
		{
			getFamiliarEntity().setPosition(getFamiliarEntityFightPos());
		}
		
		if (getFamiliarEntity().getPosition() == getFamiliarEntityFightPos())
		{
			getFamiliarEntity().idle();
			inited++;
		}
	}
	else
	{
		inited++;
	}
	
	if (inited == 2 && getEnemyEntity().getPosition().x > getEnemyEntityFightPos().x)
	{
		getEnemyEntity().move(-getEntitySpeed(),0);
		
		if (getEnemyEntity().getPosition().x < getEnemyEntityFightPos().x)
		{
			getEnemyEntity().setPosition(getEnemyEntityFightPos());
		}
		
		if (getEnemyEntity().getPosition() == getEnemyEntityFightPos())
		{
			getEnemyEntity().idle();
			inited++;
		}
	}
	else if (getEnemyEntity().getPosition().x >= getEnemyEntityFightPos().x)
	{
		inited++;
	}
	
	if (inited == 3)
	{
		getTags().remove(GameTags::START);
		getTags().add(GameTags::FIGHT);
	}
};

void Game::fightPhase()
{
	if (getPlayerEntity().isAlive() && getEnemyEntity().isAlive())
	{
		getQte().update();
		
		getPlayerEntity().generateAttack(getEnemyEntity());
		getFamiliarEntity().generateAttack(getEnemyEntity());
		getEnemyEntity().generateAttack(getPlayerEntity());
	}
	else
	{
		getQte().resetCursor();
		getQte().getBlocks().clear();
	}
	
	PlayerEntity & pl = getPlayerEntity();
	EnemyEntity & en = getEnemyEntity();
	FamiliarEntity & fa = getFamiliarEntity();
	
	static bool pl_waiting = false;
	static bool en_waiting = false;
	
	if (en.isAlive() || pl.isAlive())
	{
		
		//	PLAYER
		
		if (pl.isAlive() && en.isAlive() && pl.attack(en))
		{
			
			if (en.isDead() && !en.isIdling())
			{
				pl.idle();
				
				pl_waiting = true;
			}
		}
		else if (pl_waiting && pl.isIdling() && en.isIdling())
		{
			pl.attack(en, true);
			pl_waiting = false;
		}
		else if ((pl.isAlive() && pl.getSprite().isAtLastStep()) || (pl.isDead() && en.getSprite().isAtLastStep() && en_waiting))
		{
			pl.idle();
		}
		else if (pl.isDead() && !pl.isDying() && pl.isIdling() && en.isIdling())
		{
			pl.die();
		}
		
		//	FAMILIAR
		
		if (pl.isAlive() && en.isAlive() && fa.attack(en))
		{
			if (en.isDead() && !en.isIdling())
			{
				fa.idle();
				
				pl_waiting = true;
			}
		}
		else if (pl_waiting && fa.isIdling() && en.isIdling())
		{
			fa.attack(en, true);
			pl_waiting = false;
		}
		else if ((pl.isAlive() && fa.getSprite().isAtLastStep()) || (pl.isDead() && fa.getSprite().isAtLastStep()))
		{
			fa.idle();
		}
		
		//	ENEMY
		
		if (en.isAlive() && pl.isAlive() && en.attack(pl))
		{
			if (pl.isDead() && !pl.isIdling())
			{
				en.idle();
				
				en_waiting = true;
			}
		}
		else if (en_waiting && en.isIdling() && pl.isIdling())
		{
			en.attack(en, true);
			en_waiting = false;
		}
		else if ((en.isAlive() && en.getSprite().isAtLastStep()) || (en.isDead() && en.getSprite().isAtLastStep() && pl_waiting))
		{
			en.idle();
		}
		else if (en.isDead() && !en.isDying() && en.isIdling() && pl.isIdling() && !(fa.isAttacking() && !fa.getSprite().isAtLastStep()))
		{
			en.die();
		}
		
	}
	else
	{
		if (!en.isDying()) en.attack(pl, true);

		if (pl.isDead() && pl.getSprite().isAtLastStep())
		{
			pl.die();
		}
		
		if (fa.isAttacking() && fa.getSprite().isAtLastStep())
		{
			fa.idle();
		}

		if (en.isDead() && en.getSprite().isAtLastStep())
		{
			en.die();
		}
	}
	
	getEnemyEntityStats().refresh();
	getPlayerEntityStats().refresh();
	
	if ( getPlayerEntity().isAlive() && getPlayerEntity().isIdling() && getEnemyEntity().isDead() && getEnemyEntity().isDying() && getEnemyEntity().getSprite().isAtLastStep())
	{
		pl_waiting = false;
		en_waiting = false;
		
		getTags().remove(GameTags::FIGHT);
		getTags().add(GameTags::BONUS);
		getBonus().shuffle();
	}
	
	if ( getPlayerEntity().isDead() && getPlayerEntity().isDying() && getPlayerEntity().getSprite().isAtLastStep() && ( (getEnemyEntity().isAlive()) || (getEnemyEntity().isDead() && getEnemyEntity().isDying() && getEnemyEntity().getSprite().isAtLastStep()) ) )
	{
		pl_waiting = false;
		en_waiting = false;
		
		getGameOver().refresh(getLevelIndicator().getLevel()-1, getBestScore());
		setBestScore((getLevelIndicator().getLevel()-1 > getBestScore()) ? getLevelIndicator().getLevel()-1 : getBestScore());
		save();
		
		getTags().remove(GameTags::FIGHT);
		getTags().add(GameTags::GAMEOVER);
	}
};

void Game::bonusPhase()
{
	if (getBonus().checkChoice())
	{
		getPlayerEntityStats().refresh();
		
		getTags().remove(GameTags::BONUS);
		getTags().add(GameTags::REINIT);
		
		getLevelIndicator().nextLevel();
	}
};

void Game::reinitPhase()
{
	if (getEnemyEntity().getPosition() != getEnemyEntityDispawnPos() && getEnemyEntity().isDead())
	{
		getPlateform().update();
		getBackground().update();
		
		getEnemyEntity().move(-getEntitySpeed(), 0);
		getPlayerEntity().run();
		getFamiliarEntity().run();
		
		if (getEnemyEntity().getPosition().x <= getEnemyEntityDispawnPos().x && getEnemyEntity().isDead())
		{
			getQte().setCursor(getQte().getCursor());
			getQte().getCursor().setDefaultSpeed();
			
			setEnemyEntity(getRandomEnemyEntity());
			EnemyEntityLeveling::apply(getEnemyEntity(), getLevelIndicator().getLevel());
			
			getEnemyEntity().setPosition(getEnemyEntitySpawnPos());
			getEnemyEntity().setState(Entity::State::RUN);
			
			getEnemyEntityStats().setTarget(&getEnemyEntity());
			getEnemyEntityStats().refresh();
		}
	}
	else if (getEnemyEntity().isAlive() && getEnemyEntity().getPosition() != getEnemyEntityFightPos())
	{
		getPlateform().update();
		getBackground().update();
		
		getEnemyEntity().move(-getEntitySpeed()*1.5f,0);
		
		if (getEnemyEntity().getPosition().x < getEnemyEntityFightPos().x)
		{
			getEnemyEntity().setPosition(getEnemyEntityFightPos());
		}
	}
	else
	{
		getEnemyEntity().idle();
		getPlayerEntity().idle();
		getFamiliarEntity().idle();
		
		getTags().remove(GameTags::REINIT);
		getTags().add(GameTags::FIGHT);
	}
};

void Game::gameOverPhase()
{
	int choice = getGameOver().checkChoice();
	
	if (choice == 1)
	{
		getTags().remove(GameTags::GAMEOVER);
		getTags().add(GameTags::INIT);
	}
	else if (choice == 2)
	{
		getTags().clear();
		getWindow().close();
	}
	
};

void Game::draw()
{
	getWindow().clear(sf::Color(50,50,50));
	
	getWindow().draw(getBackground());
	getWindow().draw(getPlateform());
	
	if (!getTags().contains(GameTags::INIT))
	{
		getWindow().draw(getEnemyEntity());
		getWindow().draw(getFamiliarEntity());
		getWindow().draw(getPlayerEntity());
	}
	
	getWindow().draw(getEnemyEntityStats());
	getWindow().draw(getPlayerEntityStats());
	getWindow().draw(getQte());
	getWindow().draw(getLevelIndicator());
	
	if (getTags().contains(GameTags::BONUS))
	{
		getWindow().draw(getBonus());
	}
	
	if (getTags().contains(GameTags::GAMEOVER))
	{
		getWindow().draw(getGameOver());
	}
	
	getWindow().display();
	
	getChrono().stop();
}

void Game::wait()
{
	while (getChrono().getDuration().count() < (1.f / (float)getFps()))
	{
		usleep( ceil((((1.f/(float)getFps()) - getChrono().getDuration().count() ) * 1000000 ) * 0.75 ) );
		getChrono().stop();
	}
};

void Game::save()
{
	std::ofstream file;
	file.open ("content/Save/save.txt", std::ios::out | std::ios::trunc);
	file << std::to_string(getBestScore());
	file.close();
}

void Game::clear()
{

};

