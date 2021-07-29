//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#include "LifeGauge.h"
#include "Global/GlobalTextureManager.h"

LifeGauge::LifeGauge() : Gauge<Entity>(tm.get("gauge_life"), sf::Vector2i(134, 12))
{

}

LifeGauge::LifeGauge(Entity &target) : LifeGauge()
{
	setTarget(target);
	refresh();
}

float LifeGauge::getPercentFromTarget() const
{
	return ((float)target->getLifePoint()/(float)target->getLifePointMax()) * 100.0f;
}

void LifeGauge::setPercent(float percent)
{
	Gauge::setPercent(percent);
	
	uint8_t red = 255;
	uint8_t green = 255;
	if 		((getPercent()/100.f) >= 0 && (getPercent()/100.f) <= 0.5)	{green = 510 * (getPercent()/100.f);}
	else if ((getPercent()/100.f) > 0.5 && (getPercent()/100.f) <= 1)	{red = -510 * (getPercent()/100.f) + 510;}
	setColor(sf::Color(red, green, 0));
}
