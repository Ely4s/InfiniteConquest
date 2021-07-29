#include <__bit_reference>
//
// Created by Elyas EL IDRISSI on 27/02/2021.
//

#include "Flippable.h"

bool Flippable::getIsFlip() const
{
	return isFlip;
}

void Flippable::setIsFlip(bool isFlip)
{
	Flippable::isFlip = isFlip;
}

void Flippable::flip()
{
	setIsFlip(!(getIsFlip()));
}

void Flippable::flip(Side side)
{
	( (side == LEFT && !getIsFlip()) || (side == RIGHT && getIsFlip()) ) ? flip() : void ();
}


