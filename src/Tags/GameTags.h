//
// Created by Elyas EL IDRISSI on 25/03/2021.
//

#ifndef INFINITECONQUEST_GAMETAGS_H
#define INFINITECONQUEST_GAMETAGS_H

#include "Tags.h"

class GameTags : public Tags
{

public :
	
	GameTags() = default;
	~GameTags() = default;
	
	enum Value
	{
		INIT,
		START,
		REINIT,
		FIGHT,
		BONUS,
		GAMEOVER,
	};
	
	inline static hashmap::unordered_map<int, std::string> LABELS
	{
		{INIT, "INIT"},
		{START, "START"},
		{REINIT, "REINIT"},
		{FIGHT, "FIGHT"},
		{BONUS, "BONUS"},
		{GAMEOVER, "GAMEOVER"}
	};
	
	hashmap::unordered_map<int, std::string> &getLabels() const;
};


#endif //INFINITECONQUEST_GAMETAGS_H
