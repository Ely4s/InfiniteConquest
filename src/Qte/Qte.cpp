//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#include "Qte.h"

#include "QteBlock.h"
#include "Utils/DebugRect.h"

Qte::Qte()
{
	setOrigin(getSize().x/2.f, getSize().y/2.f);
	setBar(getBar());
	setCursor(getCursor());
};

Qte::~Qte()
{
	clearBlocks();
}

void Qte::update()
{
	updateBlocks();
	updateCursor();
};

void Qte::updateBlocks()
{
	QteBlock * block;
	
	for (auto it = getBlocks().begin(); it != getBlocks().end(); ++it)
	{
		block = *it;
		
		if (block->getTags().contains(QteTags::DELETABLE))
		{
			getBlocks().erase(it);
			delete block;
			--it;
		}
		else
		{
			block->update();
		}
	}
};

void Qte::updateCursor()
{
	getCursor().move((float)getCursor().getDirX() * getCursor().getSpeed(), 0);
	
	if ( getCursor().getTopLeft().x + getCursor().getSize().x > getBar().getTopLeft().x + getBar().getSize().x - getBar().getRightOffset())
	{
		getCursor().setPosition(getBar().getTopLeft().x + getBar().getSize().x - getBar().getRightOffset() - getCursor().getOrigin().x, getCursor().getPosition().y);
		getCursor().setDirX(-1);
	}
	else if ( getCursor().getTopLeft().x < getBar().getTopLeft().x + getBar().getLeftOffset())
	{
		getCursor().setPosition(getBar().getTopLeft().x + getBar().getLeftOffset() + getCursor().getOrigin().x, getCursor().getPosition().y);
		getCursor().setDirX(1);
	}
};

void Qte::addBlock(QteBlock * block)
{
	blocks.push_back(block);
};

const QteBar &Qte::getBar() const
{
	return bar;
}

QteBar &Qte::getBar()
{
	return bar;
}

void Qte::setBar(const QteBar &bar)
{
	Qte::bar = bar;
	getBar().setOrigin(getBar().getSize().x/2.f, getBar().getSize().y/2.f);
}

QteCursor &Qte::getCursor()
{
	return cursor;
}

const QteCursor &Qte::getCursor() const
{
	return cursor;
}

void Qte::setCursor(const QteCursor &cursor)
{
	Qte::cursor = cursor;
	getCursor().setPosition(getBar().getTopLeft().x + getCursor().getOrigin().x + getBar().getLeftOffset(), getBar().getTopLeft().y + getBar().getOrigin().y);
}

void Qte::resetCursor()
{
	setCursor(getCursor());
	getCursor().setDefaultSpeed();
}

void Qte::setBlocks(const std::vector<QteBlock*> &blocks)
{
	Qte::blocks = blocks;
}

std::vector<QteBlock *> &Qte::getBlocks()
{
	return blocks;
}

const std::vector<QteBlock *> &Qte::getBlocks() const
{
	return blocks;
}

void Qte::clearBlocks()
{
	QteBlock * block;
	
	for (auto it = getBlocks().begin(); it != getBlocks().end(); ++it)
	{
		block = *it;
		getBlocks().erase(it);
		delete block;
		--it;
	}
}

void Qte::setPosition(float x, float y)
{
	sf::Vector2f offSet = {x - getPosition().x, y - getPosition().y};
	Transformable::setPosition(x, y);
	getBar().move(offSet);
	getCursor().move(offSet);
	for (auto &block : blocks) {block->move(offSet);}
}

void Qte::setPosition(const sf::Vector2f &position)
{
	Transformable::setPosition(position);
}

void Qte::setRotation(float angle)
{
	float offSet = angle - getRotation();
	Transformable::setRotation(angle);
	getBar().rotate(offSet);
	getCursor().rotate(offSet);
	for (auto &block : blocks) {block->rotate(offSet);}
}

void Qte::setOrigin(float x, float y)
{
	sf::Vector2f offSet = {x - getOrigin().x, y - getOrigin().y};
	Transformable::setOrigin(x, y);
	getBar().setOrigin(getBar().getOrigin().x + offSet.x, getBar().getOrigin().y + offSet.y);
	getCursor().setOrigin(getCursor().getOrigin().x + offSet.x, getCursor().getOrigin().y + offSet.y);
	for (auto &block : blocks) {block->setOrigin(block->getOrigin().x + offSet.x, block->getOrigin().y + offSet.y);}
}

void Qte::setOrigin(const sf::Vector2f &origin)
{
	Transformable::setOrigin(origin);
}

void Qte::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(getBar());

	for (const auto &block : getBlocks())
	{
		target.draw(*block);
	}

	target.draw(getCursor());
}