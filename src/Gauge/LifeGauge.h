//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#ifndef INFINITECONQUEST_LIFEGAUGE_H
#define INFINITECONQUEST_LIFEGAUGE_H

#include "Gauge.h"
#include "Entity/Entity.h"

class LifeGauge : public Gauge<Entity>
{

public:
	
	LifeGauge();
	explicit LifeGauge(Entity &target);
	float getPercentFromTarget() const override;

protected:
	
	void setPercent(float percent) override;
};


#endif //INFINITECONQUEST_LIFEGAUGE_H
