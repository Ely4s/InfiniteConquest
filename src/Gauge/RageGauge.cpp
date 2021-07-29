//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#include "RageGauge.h"
#include "Global/GlobalTextureManager.h"
#include "Entity/Entity.h"

RageGauge::RageGauge() : Gauge<PlayerEntity>(tm.get("gauge_life"), sf::Vector2i(134, 12))
{
	setColor(sf::Color(40, 170, 248));
}

RageGauge::RageGauge(PlayerEntity &target) : RageGauge()
{
	setTarget(target);
	refresh();
}

float RageGauge::getPercentFromTarget() const
{
	return ((float)target->getRage()/(float)target->getRageMax()) * 100.0f;
}

void RageGauge::setPercent(float percent)
{
	Gauge::setPercent(percent);
	
	if (percent == 100)
	{
		setColor(sf::Color(0, 228, 255));
	}
	else
	{
		setColor(sf::Color(40, 170, 248));
	}
}

//sf::Color(40, 190, 240);
//sf::Color(225, 0, 0);