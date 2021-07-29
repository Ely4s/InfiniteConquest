//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#ifndef INFINITECONQUEST_QTEPLAYERFAILBLOCK_H
#define INFINITECONQUEST_QTEPLAYERFAILBLOCK_H

#include "QteBlock.h"

class QtePlayerFailBlock : public QteBlock
{

public:
	
	QtePlayerFailBlock();
	
	void update() override;
	bool active(const Entity &entity, Entity &entitySource, Entity &entityTarget) override;
	
protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	
};


#endif //INFINITECONQUEST_QTEPLAYERFAILBLOCK_H
