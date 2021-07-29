#include <__bit_reference>
//
// Created by Elyas EL IDRISSI on 27/02/2021.
//

#ifndef INFINITECONQUEST_FLIPABLE_H
#define INFINITECONQUEST_FLIPABLE_H


class Flippable
{

public:
	
	enum Side{LEFT, RIGHT};
	
	virtual bool getIsFlip() const;
	
	virtual void flip();
	
	virtual void flip(Side side);
	
private:
	
	bool isFlip = false;
	
	virtual void setIsFlip(bool isFlip);
};


#endif //INFINITECONQUEST_FLIPABLE_H
