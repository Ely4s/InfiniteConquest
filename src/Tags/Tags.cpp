//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#include "Tags.h"

void Tags::clear()
{
	tags.clear();
};

bool Tags::isValid(int tag) const
{
	return (tag >= 0 && tag < getLabels().size());
}

std::string Tags::toString(int tag) const
{
	return (isValid(tag)) ? getLabels().at(tag) : "";
};

void Tags::add(int tag)
{
	
	if (isValid(tag)) {
		tags.push_back(toString(tag));
	};
};

void Tags::remove(int tag)
{
	if (contains(tag))
	{
		tags.erase(std::find(tags.begin(), tags.end(), toString(tag)));
	}
};

bool Tags::contains(int tag) const
{
	return std::binary_search(tags.begin(), tags.end(), toString(tag));
}