//
// Created by Elyas EL IDRISSI on 01/03/2021.
//

#ifndef INFINITECONQUEST_QTEBLOCK_H
#define INFINITECONQUEST_QTEBLOCK_H

#include <thread>

#include "Sprite/SpriteSheet.h"
#include "Window/Event.h"
#include "Game/GameEntityRole.h"
#include "Entity/Entity.h"
#include "Tags/QteTags.h"
#include "Qte.h"

class QteBlock : public SpriteSheet
{

public:
	
	QteBlock() = default;
	QteBlock(const Texture &texture, const sf::Vector2f &textureRect, const GameEntityRole::Role &source, const GameEntityRole::Role &target, float speed = 1);
	~QteBlock() = default;
	
	float getSpeed() const;
	void setSpeed(float speed);
	
	const GameEntityRole::Role &getSource() const;
	void setSource(const GameEntityRole::Role &source);
	
	const GameEntityRole::Role &getTarget() const;
	void setTarget(const GameEntityRole::Role &target);
	
	virtual void update() = 0;
	virtual bool active(const Entity &entity, Entity &entitySource, Entity &entityTarget) = 0;
	
	const QteTags &getTags() const;
	QteTags &getTags();
	void setTags(const QteTags &tags);
	
private:
	
	QteTags tags{};
	
	GameEntityRole::Role source{};
	GameEntityRole::Role target{};
	
	float speed{};
	
	bool isActived = false;
};


#endif //INFINITECONQUEST_QTEBLOCK_H
