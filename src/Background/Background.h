//
// Created by Elyas EL IDRISSI on 06/04/2021.
//

#ifndef INFINITECONQUEST_BACKGROUND_H
#define INFINITECONQUEST_BACKGROUND_H

#include "Sprite/Sprite.h"
#include "Sprite/Texture.h"
#include "Interface/Transformable.h"
#include "Interface/Drawable.h"

class Background : public Transformable, public Drawable
{

public:
	
	Background(const std::string& textureId, const sf::Vector2f &selfSize, const sf::Vector2f &size, float speed, int dirX);
	
	void update();
	
	std::vector<Sprite> &getBackgrounds();
	const std::vector<Sprite> &getBackgrounds() const;
	void setBackgrounds(const std::vector<Sprite> &backgrounds);
	
	float getSpeed() const;
	void setSpeed(float speed);
	
	int getDirX() const;
	void setDirX(int dirX);
	
	void setPosition(float x, float y) override;
	
	void setPosition(const sf::Vector2f &position) override;
	
	void setOrigin(float x, float y) override;
	
	void setOrigin(const sf::Vector2f &origin) override;

protected:
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	
	std::vector<Sprite> backgrounds;
	float speed = 1;
	int dirX = -1;
	
	float getMaxX();
	float getMinX();
};


#endif //INFINITECONQUEST_BACKGROUND_H
