//
// Created by Elyas EL IDRISSI on 01/04/2021.
//

#ifndef INFINITECONQUEST_PLAYERENTITYSTATS_H
#define INFINITECONQUEST_PLAYERENTITYSTATS_H

#include "Sprite/Sprite.h"
#include "Gauge/LifeGauge.h"
#include "Gauge/RageGauge.h"
#include "Text/Text.h"
#include "Entity/FamiliarEntity.h"
#include "Stats/EntityStats.h"

class PlayerEntityStats : public EntityStats<PlayerEntity>
{

public:
	
	PlayerEntityStats();
	PlayerEntityStats(PlayerEntity * playerTarget, FamiliarEntity * familiarTarget);
	
	void refresh();
	void rageGaugeRefresh();
	void rageTextRefresh();
	void familiarAttackTextRefresh();
	
	RageGauge &getRageGauge();
	const RageGauge &getRageGauge() const;
	void setRageGauge(const RageGauge &rageGauge);
	
	Text &getFamiliarAttackText();
	const Text &getFamiliarAttackText() const;
	void setFamiliarAttackText(const Text &familiarAttackText);
	
	Text &getRageText();
	const Text &getRageText() const;
	void setRageText(const Text &playerRageText);
	
	void setTarget(PlayerEntity * entityTarget) override;
	
	FamiliarEntity *getFamiliarTarget() const;
	void setFamiliarTarget(FamiliarEntity * familiarTarget);
	
	void setPosition(float x, float y) override;
	
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	
	void setOrigin(const sf::Vector2f &origin) override;


protected:

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	
private:
	
	FamiliarEntity * familiarTarget = nullptr;
	
	RageGauge rageGauge;
	
	Text playerRageText;
	Text familiarAttackText;
};


#endif //INFINITECONQUEST_PLAYERENTITYSTATS_H
