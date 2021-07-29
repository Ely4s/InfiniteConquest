//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#ifndef INFINITECONQUEST_QTEPLAYERBLOCK_H
#define INFINITECONQUEST_QTEPLAYERBLOCK_H

#include "QteBlock.h"

class QtePlayerBlock : public QteBlock
{

public:
	
	QtePlayerBlock();
	
	void update() override;
	bool active(const Entity &entity, Entity &entitySource, Entity &entityTarget) override;
};




#endif //INFINITECONQUEST_QTEPLAYERBLOCK_H
