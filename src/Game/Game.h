//
// Created by Elyas EL IDRISSI on 12/03/2021.
//

#ifndef INFINITECONQUEST_GAME_H
#define INFINITECONQUEST_GAME_H

#include <thread>
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
#include "GameContent.h"

class Game : public GameEntityRole, public GameContent
{

public:
	
	Game();
	~Game(){clear();};
	
	void init();
	void loadSave();
	void update();
	void draw();
	void wait();
	void save();
	void clear();
	
	void initPhase();
	void startPhase();
	void fightPhase();
	void bonusPhase();
	void reinitPhase();
	void gameOverPhase();
	
	Game(const Game& other);
	Game& operator=(const Game& other);
};

#endif //INFINITECONQUEST_GAME_H
