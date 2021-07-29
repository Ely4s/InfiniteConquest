//
// Created by Elyas EL IDRISSI on 16/03/2021.
//

#ifndef INFINITECONQUEST_ENTITYTYPE_H
#define INFINITECONQUEST_ENTITYTYPE_H

#include "Library/hashmap.h"

class EntityType
{

public:
	
	enum Type{TYPE_PLAYER, TYPE_FAMILIAR, TYPE_ENEMY, TYPE_BOSS};
	inline static hashmap::unordered_map<Type, std::string> TYPE_LABEL {{TYPE_PLAYER, "Type_Player"}, {TYPE_FAMILIAR, "Type_Familiar"}, {TYPE_ENEMY, "Type_Enemy"}, {TYPE_BOSS, "Type_Boss"}};
	
};


#endif //INFINITECONQUEST_ENTITYTYPE_H
