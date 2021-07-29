//
// Created by Elyas EL IDRISSI on 01/03/2021.
//

#include "QteBlock.h"

QteBlock::QteBlock(const Texture &texture, const sf::Vector2f &textureRect, const GameEntityRole::Role &source, const GameEntityRole::Role &target, float speed)
		: SpriteSheet(texture, textureRect, 1), source(source), target(target), speed(speed)
{
	setOrigin(getTextureRect().width/2.f, getTextureRect().height/2.f);
	getTags().add(QteTags::ACTIVABLE);
}

const GameEntityRole::Role &QteBlock::getSource() const
{
	return source;
};

void QteBlock::setSource(const GameEntityRole::Role &source)
{
	QteBlock::source = source;
};

const GameEntityRole::Role &QteBlock::getTarget() const
{
	return target;
};

void QteBlock::setTarget(const GameEntityRole::Role &target)
{
	QteBlock::target = target;
};

float QteBlock::getSpeed() const
{
	return speed;
}

void QteBlock::setSpeed(float speed)
{
	QteBlock::speed = (speed < 0) ? 0 : speed;
}

const QteTags &QteBlock::getTags() const
{
	return tags;
}

QteTags &QteBlock::getTags()
{
	return tags;
}

void QteBlock::setTags(const QteTags &tags)
{
	QteBlock::tags = tags;
}

