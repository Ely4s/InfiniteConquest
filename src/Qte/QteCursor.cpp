//
// Created by Elyas EL IDRISSI on 01/03/2021.
//

#include "QteCursor.h"

#include "Global/GlobalTextureManager.h"

QteCursor::QteCursor() : Sprite(tm.get("qte_cursor"), sf::Vector2f (14, 52)), speedMin(3), speedMax(10), speedStepNumber(5), dirX(1)
{
	setDefaultSpeed();
	setOrigin(getTextureRect().width/2.f, getTextureRect().height/2.f);
}

void QteCursor::setDefaultSpeed()
{
	setSpeedStep(0);
	setSpeed(getSpeedMin());
}

void QteCursor::speedUp()
{
	setSpeedStep(getSpeedStep()+1);
	setSpeed((getSpeedMin() + (float)getSpeedStep() ) * ( (float)( getSpeedMax() -  getSpeedMin() ) / (float)getSpeedStepNumber() ) );
};

void QteCursor::speedDown()
{
	setSpeedStep(getSpeedStep()-1);
	setSpeed((getSpeedMin() + (float)getSpeedStep() ) * ( (float)( getSpeedMax() -  getSpeedMin() ) / (float)getSpeedStepNumber() ) );
};

int QteCursor::getSpeedStep() const
{
	return speedStep;
}

void QteCursor::setSpeedStep(int speedStep)
{
	QteCursor::speedStep = (speedStep < 0) ? 0 : (speedStep > getSpeedStepNumber()) ? getSpeedStepNumber() : speedStep;
}

int QteCursor::getSpeedStepNumber() const
{
	return speedStepNumber;
};

void QteCursor::setSpeedStepNumber(int speedStepNumber)
{
	QteCursor::speedStepNumber = speedStepNumber;
	setSpeedStep(getSpeedStep());
};

float QteCursor::getSpeed() const
{
	return speed;
}

void QteCursor::setSpeed(float speed)
{
	QteCursor::speed = (speed < 0 ) ? 0 : (speed < getSpeedMin()) ? getSpeedMin() : (speed > getSpeedMax()) ? getSpeedMax() : speed;
}

float QteCursor::getSpeedMin() const
{
	return speedMin;
}

void QteCursor::setSpeedMin(float speedMin)
{
	QteCursor::speedMin = (speedMin < 0) ? 0 : (speedMin > getSpeedMax()) ? getSpeedMax() : speedMin;
	setSpeed(getSpeed());
}

float QteCursor::getSpeedMax() const
{
	return speedMax;
}

void QteCursor::setSpeedMax(float speedMax)
{
	QteCursor::speedMax = (speedMax < 0) ? 0 : (speedMax < getSpeedMin()) ? getSpeedMin() : speedMax;
	setSpeed(getSpeed());
}

int QteCursor::getDirX() const
{
	return dirX;
}

void QteCursor::setDirX(int dirX)
{
	if (dirX > 0)
	{
		QteCursor::dirX = 1;
	}
	else
	{
		QteCursor::dirX = -1;
	}
	
}

void QteCursor::reverseDir()
{
	setDirX(-getDirX());
};
