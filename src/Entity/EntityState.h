//
// Created by Elyas EL IDRISSI on 16/03/2021.
//

#ifndef INFINITECONQUEST_ENTITYSTATE_H
#define INFINITECONQUEST_ENTITYSTATE_H

#include "Library/hashmap.h"

class EntityState
{

public:
	
	enum State{IDLE, RUN, ATTACK, DEATH};
	inline static hashmap::unordered_map<State, std::string> STATES_LABEL {{IDLE, "idle"},{RUN, "run"},{ATTACK, "attack"},{DEATH, "death"}};

};


#endif //INFINITECONQUEST_ENTITYSTATE_H
