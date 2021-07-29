//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#include "GameContent.h"

#include <algorithm>
#include <random>

#include "Global/GlobalEnemyEntityFactory.h"

unsigned int GameContent::getFps() const
{
	return FPS;
}
void GameContent::setFps(unsigned int fps)
{
	FPS = fps;
}


Window &GameContent::getWindow()
{
	return window;
}

Event &GameContent::getEvent()
{
	return event;
}
void GameContent::setEvent(const Event &event)
{
	GameContent::event = event;
}

PlayerEntity &GameContent::getPlayerEntity()
{
	return playerEntity;
}
void GameContent::setPlayerEntity(const PlayerEntity &playerEntity)
{
	GameContent::playerEntity = playerEntity;
}

EnemyEntity &GameContent::getEnemyEntity()
{
	return enemyEntity;
}
void GameContent::setEnemyEntity(const EnemyEntity &enemyEntity)
{
	GameContent::enemyEntity = enemyEntity;
}

FamiliarEntity &GameContent::getFamiliarEntity()
{
	return familiarEntity;
}
void GameContent::setFamiliarEntity(const FamiliarEntity &familiarEntity)
{
	GameContent::familiarEntity = familiarEntity;
}

PlayerEntityStats &GameContent::getPlayerEntityStats()
{
	return playerEntityStats;
}
void GameContent::setPlayerEntityStats(const PlayerEntityStats &playerEntityStats)
{
	GameContent::playerEntityStats = playerEntityStats;
}

EnemyEntityStats &GameContent::getEnemyEntityStats()
{
	return enemyEntityStats;
}
void GameContent::setEnemyEntityStats(const EnemyEntityStats &enemyEntityStats)
{
	GameContent::enemyEntityStats = enemyEntityStats;
}

sf::Vector2f GameContent::getPlayerEntitySpawnPos()
{
	return sf::Vector2f(getWindow().getView().getTopLeft().x - getPlayerEntity().getSize().x + getPlayerEntity().getOrigin().x, getWindow().getView().getTopLeft().y + 295);
}
sf::Vector2f GameContent::getPlayerEntityFightPos()
{
	return sf::Vector2f(getWindow().getView().getTopLeft().x + 250,getWindow().getView().getTopLeft().y + 295);
}

sf::Vector2f GameContent::getEnemyEntitySpawnPos()
{
	return sf::Vector2f(getWindow().getView().getTopLeft().x + getWindow().getView().getSize().x + getEnemyEntity().getOrigin().x, getWindow().getView().getTopLeft().y + 295);
}
sf::Vector2f GameContent::getEnemyEntityDispawnPos()
{
	return sf::Vector2f(getWindow().getView().getTopLeft().x - getEnemyEntity().getSize().x + getEnemyEntity().getOrigin().x, getWindow().getView().getTopLeft().y + 295);
}
sf::Vector2f GameContent::getEnemyEntityFightPos()
{
	return sf::Vector2f(getWindow().getView().getTopLeft().x + getWindow().getView().getSize().x - 135, getWindow().getView().getTopLeft().y + 295);
}

sf::Vector2f GameContent::getFamiliarEntitySpawnPos()
{
	return sf::Vector2f(getPlayerEntitySpawnPos().x - (getPlayerEntityFightPos().x - getFamiliarEntityFightPos().x), getWindow().getView().getTopLeft().y + 295);
}
sf::Vector2f GameContent::getFamiliarEntityFightPos()
{
	return sf::Vector2f(getWindow().getView().getTopLeft().x + 105, getWindow().getView().getTopLeft().y + 295);
}

float GameContent::getEntitySpeed() const
{
	return entitySpeed;
}
void GameContent::setEntitySpeed(float entitySpeed)
{
	GameContent::entitySpeed = entitySpeed;
}

Qte &GameContent::getQte()
{
	return qte;
}
void GameContent::setQte(const Qte &qte)
{
	GameContent::qte = qte;
}

Chrono &GameContent::getChrono()
{
	return chrono;
}
void GameContent::setChrono(const Chrono &chronoLogic)
{
	GameContent::chrono = chronoLogic;
}

GameTags &GameContent::getTags()
{
	return tags;
}
void GameContent::setTags(const GameTags &tags)
{
	GameContent::tags = tags;
}

BonusChoices &GameContent::getBonus()
{
	return bonus;
}
void GameContent::setBonus(const BonusChoices &bonus)
{
	GameContent::bonus = bonus;
}

LevelIndicator &GameContent::getLevelIndicator()
{
	return levelIndicator;
}
const LevelIndicator &GameContent::getLevelIndicator() const
{
	return levelIndicator;
}
void GameContent::setLevelIndicator(const LevelIndicator &levelIndicator)
{
	GameContent::levelIndicator = levelIndicator;
}

GameOver &GameContent::getGameOver()
{
	return gameOver;
}
const GameOver &GameContent::getGameOver() const
{
	return gameOver;
}
void GameContent::setGameOver(const GameOver &gameOver)
{
	GameContent::gameOver = gameOver;
}

unsigned int GameContent::getBestScore() const
{
	return bestScore;
}
void GameContent::setBestScore(unsigned int bestScore)
{
	GameContent::bestScore = bestScore;
}

Background &GameContent::getPlateform()
{
	return plateform;
}

const Background &GameContent::getPlateform() const
{
	return plateform;
}

void GameContent::setPlateform(const Background &plateform)
{
	GameContent::plateform = plateform;
}

Background &GameContent::getBackground()
{
	return background;
}

const Background &GameContent::getBackground() const
{
	return background;
}

void GameContent::setBackground(const Background &background)
{
	GameContent::background = background;
}

const EnemyEntity GameContent::getRandomEnemyEntity()
{
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
	
	std::default_random_engine rng(std::chrono::system_clock::now().time_since_epoch().count());
	std::shuffle(std::begin(enemiesId), std::end(enemiesId), rng);
	
	return eef.get(enemiesId.at(0));
}
