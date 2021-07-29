//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#ifndef INFINITECONQUEST_GAMECONTENT_H
#define INFINITECONQUEST_GAMECONTENT_H

#include <SFML/Graphics.hpp>

#include "Window/Window.h"
#include "Entity/PlayerEntity.h"
#include "Entity/EnemyEntity.h"
#include "Entity/FamiliarEntity.h"
#include "Gauge/LifeGauge.h"
#include "Gauge/RageGauge.h"
#include "Qte/Qte.h"
#include "Window/Event.h"
#include "Utils/Chrono.h"
#include "GameEntityRole.h"
#include "Interface/Drawable.h"
#include "Tags/GameTags.h"
#include "Stats/PlayerEntityStats.h"
#include "Stats/EnemyEntityStats.h"
#include "Bonus/BonusChoices.h"
#include "Level/LevelIndicator.h"
#include "GameOver/GameOver.h"
#include "Background/Background.h"

class GameContent
{

public :
	
	unsigned int getFps() const;
	void setFps(unsigned int fps);
	
	Window &getWindow();
	
	Event &getEvent();
	void setEvent(const Event &event);
	
	PlayerEntity &getPlayerEntity();
	void setPlayerEntity(const PlayerEntity &playerEntity);
	
	EnemyEntity &getEnemyEntity();
	void setEnemyEntity(const EnemyEntity &enemyEntity);
	
	FamiliarEntity &getFamiliarEntity();
	void setFamiliarEntity(const FamiliarEntity &familiarEntity);
	
	PlayerEntityStats &getPlayerEntityStats();
	void setPlayerEntityStats(const PlayerEntityStats &playerEntityStats);
	
	EnemyEntityStats &getEnemyEntityStats();
	void setEnemyEntityStats(const EnemyEntityStats &enemyEntityStats);
	
	sf::Vector2f getPlayerEntitySpawnPos();
	sf::Vector2f getPlayerEntityFightPos();
	
	sf::Vector2f getEnemyEntitySpawnPos();
	sf::Vector2f getEnemyEntityFightPos();
	sf::Vector2f getEnemyEntityDispawnPos();
	
	sf::Vector2f getFamiliarEntitySpawnPos();
	sf::Vector2f getFamiliarEntityFightPos();
	
	float getEntitySpeed() const;
	void setEntitySpeed(float entitySpeed);
	
	Qte &getQte();
	void setQte(const Qte &qte);
	
	Chrono &getChrono();
	void setChrono(const Chrono &chronoLogic);
	
	GameTags &getTags();
	void setTags(const GameTags &tags);
	
	BonusChoices &getBonus();
	void setBonus(const BonusChoices &bonus);
	
	LevelIndicator &getLevelIndicator();
	const LevelIndicator &getLevelIndicator() const;
	void setLevelIndicator(const LevelIndicator &levelIndicator);
	
	GameOver &getGameOver();
	const GameOver &getGameOver() const;
	void setGameOver(const GameOver &gameOver);
	
	unsigned int getBestScore() const;
	void setBestScore(unsigned int bestScore);
	
	Background &getPlateform();
	const Background &getPlateform() const;
	void setPlateform(const Background &plateform);
	
	Background &getBackground();
	const Background &getBackground() const;
	void setBackground(const Background &background);

	const EnemyEntity getRandomEnemyEntity();
	
private:
	
	unsigned int FPS = 0;
	
	Window window;
	
	Event event;
	
	PlayerEntity playerEntity;
	EnemyEntity enemyEntity;
	FamiliarEntity familiarEntity;
	
	float entitySpeed = 1;
	
	PlayerEntityStats playerEntityStats;
	EnemyEntityStats enemyEntityStats;
	
	Qte qte;
	
	Chrono chrono;
	
	GameTags tags;
	
	BonusChoices bonus;
	
	GameOver gameOver;
	
	LevelIndicator levelIndicator;
	
	unsigned int bestScore = 0;
	
	Background plateform = Background("plateform", {720, 189}, {720, 189}, 1, -1);
	Background background = Background("background", {720, 288}, {512, 288}, 4, -1);
	
};


#endif //INFINITECONQUEST_GAMECONTENT_H
