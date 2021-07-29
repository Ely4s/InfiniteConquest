//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#ifndef INFINITECONQUEST_QTETAGS_H
#define INFINITECONQUEST_QTETAGS_H

#include "Tags.h"

class QteTags : public Tags
{

public:
	
	QteTags()
	{
	}
	
	enum Value
	{
		SPAWN,
		DISPAWN,
		ACTIVE,
		ACTIVABLE,
		DELETABLE
	};
	
	inline static hashmap::unordered_map<int, std::string> LABELS
	{
			{SPAWN, "SPAWN"}, {DISPAWN, "DISPAWN"}, {ACTIVE, "ACTIVE"}, {ACTIVABLE, "ACTIVABLE"}, {DELETABLE, "DELETABLE"}
	};
	
	hashmap::unordered_map<int, std::string> &getLabels() const;
	
};


#endif //INFINITECONQUEST_QTETAGS_H
