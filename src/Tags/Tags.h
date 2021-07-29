//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#ifndef INFINITECONQUEST_TAGS_H
#define INFINITECONQUEST_TAGS_H

#include "Library/hashmap.h"
#include <vector>

class Tags
{

public :
	
	Tags() = default;
	~Tags() = default;
	
	void clear();
	void add(int tag);
	void remove(int tag);
	bool contains(int tag) const;
	std::string toString(int tag) const;

protected:
	
	std::vector<std::string> tags;
	bool isValid(int tag) const;
	virtual hashmap::unordered_map<int, std::string> &getLabels() const = 0;
};


#endif //INFINITECONQUEST_TAGS_H
