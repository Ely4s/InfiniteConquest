//
// Created by Elyas EL IDRISSI on 01/03/2021.
//

#include "QteBar.h"

#include "Global/GlobalTextureManager.h"

QteBar::QteBar() : SpriteSheet(tm.get("qte_bar"), sf::Vector2f(467, 40)), leftOffset(18), rightOffset(18)
{
	setOrigin(getSize().x/2.f, getSize().y/2.f);
}

float QteBar::getLeftOffset() const
{
	return leftOffset;
}

void QteBar::setLeftOffset(float leftOffset)
{
	QteBar::leftOffset = leftOffset;
}

float QteBar::getRightOffset() const
{
	return rightOffset;
}

void QteBar::setRightOffset(float rightOffset)
{
	QteBar::rightOffset = rightOffset;
}
