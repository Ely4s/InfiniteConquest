//
// Created by Elyas EL IDRISSI on 20/03/2021.
//

#ifndef INFINITECONQUEST_QTE_H
#define INFINITECONQUEST_QTE_H

#include <vector>
#include <memory>

#include "Interface/Transformable.h"
#include "QteBar.h"
#include "QteCursor.h"
#include "Utils/Instanceof.h"
#include "Interface/Drawable.h"

class QteBlock;

class Qte : public Transformable, public Drawable
{

public:
	
	Qte();
	~Qte();
	
	void update();
	void updateBlocks();
	void updateCursor();
	
	QteBar &getBar();
	const QteBar &getBar() const;
	void setBar(const QteBar &bar);
	
	QteCursor &getCursor();
	const QteCursor &getCursor() const;
	void setCursor(const QteCursor &cursor);
	void resetCursor();
	
	void addBlock(QteBlock * block);
	template<typename T> std::vector<T*> getBlocks();
	std::vector<QteBlock*> &getBlocks();
	const std::vector<QteBlock*> &getBlocks() const;
	void setBlocks(const std::vector<QteBlock*> &blocks);
	void clearBlocks();
	
	void setPosition(float x, float y) override;
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	void setOrigin(const sf::Vector2f &origin) override;
	
	void setRotation(float angle) override;
	
protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	
private:
	
	
	QteBar bar;
	QteCursor cursor;
	std::vector<QteBlock*> blocks;

};

template<typename T>
std::vector<T*> Qte::getBlocks()
{
	std::vector<T*> blocks;

	for (auto [it, block] = std::pair{getBlocks().begin(), (!getBlocks().empty()) ? *getBlocks().begin() : nullptr}; it != getBlocks().end(); ++it, block=*it)
	{
		if (instanceof<T>(block))
		{
			blocks.push_back((T*)block);
		}
	}

	return blocks;
}

#endif //INFINITECONQUEST_QTE_H
