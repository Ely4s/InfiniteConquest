//
// Created by Elyas EL IDRISSI on 01/03/2021.
//

#ifndef INFINITECONQUEST_QTECURSOR_H
#define INFINITECONQUEST_QTECURSOR_H

#include "Sprite/Sprite.h"

class QteCursor : public Sprite
{

public:
	
	QteCursor();
	
	void setDefaultSpeed();
	void speedUp();
	void speedDown();
	
	int getSpeedStep() const;
	void setSpeedStep(int speedStep);
	
	int getSpeedStepNumber() const;
	void setSpeedStepNumber(int speedStepNumber);
	
	float getSpeed() const;
	void setSpeed(float speed);
	
	float getSpeedMin() const;
	void setSpeedMin(float speedMin);
	
	float getSpeedMax() const;
	void setSpeedMax(float speedMax);
	
	int getDirX() const;
	void setDirX(int dirX);
	void reverseDir();

private:
	
	float speed{};
	float speedMin = 0;
	float speedMax = 1;
	int speedStep{};
	int speedStepNumber;
	
	int dirX{};
	
};


#endif //INFINITECONQUEST_QTECURSOR_H
