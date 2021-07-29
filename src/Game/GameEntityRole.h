//
// Created by Elyas EL IDRISSI on 16/03/2021.
//

#ifndef INFINITECONQUEST_GAMEENTITYROLE_H
#define INFINITECONQUEST_GAMEENTITYROLE_H

#include "Library/hashmap.h"

class GameEntityRole
{

public :
	
	enum Role{ENTITYROLE_PLAYER, ENTITYROLE_FAMILIAR, ENTITYROLE_ENEMY};
	inline static hashmap::unordered_map<Role, std::string> TYPE_LABEL {{ENTITYROLE_PLAYER, "EntityRole_Player"}, {ENTITYROLE_FAMILIAR, "EntityRole_Familiar"}, {ENTITYROLE_ENEMY, "EntityRole_Enemy"}};
};


#endif //INFINITECONQUEST_GAMEENTITYROLE_H
