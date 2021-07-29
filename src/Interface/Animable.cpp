//
// Created by Elyas EL IDRISSI on 28/02/2021.
//

#include "Animable.h"
#include "Global/GlobalGame.h"

void Animable::goToNextFrame()
{
	setFrameIt( ((float) ( (int)( getFrameIt() + 1.f ) ) ) );
}

void Animable::goToNextStep()
{
	setFrameIt(getFrameIt() + ( ( 1.f / (float)game.getFps() ) / getSecondPerFrame() ) );
}

void Animable::goToFirstStep()
{
	setFrameIt(0);
}

bool Animable::isAtFirstStep() const
{
	return (getFrameIt() == 0);
}

bool Animable::isAtLastStep() const
{
	return ( getFrameIt() + ( ( 1.f / (float)game.getFps() ) / getSecondPerFrame() ) >= (float)getFrameNbr() );
}

float Animable::getFrameIt() const
{
	return frameIt;
}

void Animable::setFrameIt(float frameIt)
{
	Animable::frameIt = ( frameIt < 0 || frameIt >= (float)getFrameNbr() ) ? 0.f : frameIt;
}

float Animable::getSecondPerFrame() const
{
	return secondPerFrame;
}

void Animable::setSecondPerFrame(float secondPerFrame)
{
	Animable::secondPerFrame = (secondPerFrame <= 0) ? 1.f : secondPerFrame;
}

int Animable::getFrameNbr() const
{
	return frameNbr;
}

void Animable::setFrameNbr(int frameNbr)
{
	Animable::frameNbr = frameNbr;
}