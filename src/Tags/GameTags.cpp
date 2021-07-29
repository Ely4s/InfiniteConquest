//
// Created by Elyas EL IDRISSI on 25/03/2021.
//

#include "GameTags.h"

hashmap::unordered_map<int, std::string> &GameTags::getLabels() const
{
	return GameTags::LABELS;
};