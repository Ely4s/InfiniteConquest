//
// Created by Elyas EL IDRISSI on 08/03/2021.
//

#ifndef INFINITECONQUEST_QTEENEMYBLOCK_H
#define INFINITECONQUEST_QTEENEMYBLOCK_H

#include "QteBlock.h"

class QteEnemyBlock : public QteBlock
{

public:
	
	QteEnemyBlock();
	
	void update() override;
	bool active(const Entity &entity, Entity &entitySource, Entity &entityTarget) override;
	
};

#endif //INFINITECONQUEST_QTEENEMYBLOCK_H
