//
// Created by Elyas EL IDRISSI on 16/03/2021.
//

#ifndef INFINITECONQUEST_ENTITYTEAM_H
#define INFINITECONQUEST_ENTITYTEAM_H

#include "Library/hashmap.h"

class EntityTeam
{

public:
	
	enum Team{TEAM_PLAYER, TEAM_ENEMY};
	inline static hashmap::unordered_map<Team, std::string> TEAM_LABEL {{TEAM_PLAYER, "Team_Player"},{TEAM_ENEMY, "Team_Enemy"}};
	
};


#endif //INFINITECONQUEST_ENTITYTEAM_H
