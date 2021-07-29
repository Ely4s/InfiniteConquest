//
// Created by Elyas EL IDRISSI on 07/03/2021.
//

#ifndef INFINITECONQUEST_TRANSFORMABLE_H
#define INFINITECONQUEST_TRANSFORMABLE_H

#include <SFML/Graphics.hpp>

class Transformable : public sf::Transformable
{

public:
	
	virtual const sf::Vector2f &getPosition() const;
	virtual void setPosition(float x, float y);
	virtual void setPosition(const sf::Vector2f &position);
	virtual void move(float offsetX, float offsetY);
	virtual void move(const sf::Vector2f &offset);
	virtual sf::Vector2f getTopLeft() const;
	
	virtual const sf::Vector2f &getSize() const;
	virtual void setSize(float w, float h);
	virtual void setSize(const sf::Vector2f &size);
	virtual void scaleSize(float w, float h);
	virtual void scaleSize(const sf::Vector2f &size);
	
	virtual void setRotation(float angle);
	virtual float getRotation() const;
	virtual void rotate(float angle);
	
	virtual const sf::Vector2f &getOrigin() const;
	virtual void setOrigin(float x, float y);
	virtual void setOrigin(const sf::Vector2f &origin);

protected:
	
	virtual void flipOrigin();
	
private:
	
	virtual const sf::Vector2f &getScale() const;
	virtual void setScale(float factorX, float factorY);
	virtual void setScale(const sf::Vector2f &factors);
	virtual void scale(float factorX, float factorY);
	virtual void scale(const sf::Vector2f &factor);
	
	sf::Vector2f size;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
};


#endif //INFINITECONQUEST_TRANSFORMABLE_H
