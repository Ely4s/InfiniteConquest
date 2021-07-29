//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#ifndef INFINITECONQUEST_RAGEGAUGE_H
#define INFINITECONQUEST_RAGEGAUGE_H

#include "Gauge.h"
#include "Entity/PlayerEntity.h"

class RageGauge : public Gauge<PlayerEntity>
{

public:
	
	RageGauge();
	explicit RageGauge(PlayerEntity &target);
	
	float getPercentFromTarget() const override;

protected:
	
	void setPercent(float percent) override;

private:
	
	int cooldown = 0;
	int dir = 1;
};


#endif //INFINITECONQUEST_RAGEGAUGE_H
