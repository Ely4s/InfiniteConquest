//
// Created by Elyas EL IDRISSI on 01/03/2021.
//

#ifndef INFINITECONQUEST_QTEBAR_H
#define INFINITECONQUEST_QTEBAR_H

#include "Sprite/SpriteSheet.h"
#include "Window/Event.h"

class QteBar : public SpriteSheet
{

public:
	
	QteBar();
	
	float getLeftOffset() const;
	void setLeftOffset(float leftOffset);
	
	float getRightOffset() const;
	void setRightOffset(float rightOffset);

private:
	
	float leftOffset;
	float rightOffset;
};
#endif //INFINITECONQUEST_QTEBAR_H
