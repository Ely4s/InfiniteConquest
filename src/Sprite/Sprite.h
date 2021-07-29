//
// Created by Elyas EL IDRISSI on 27/02/2021.
//

#ifndef INFINITECONQUEST_SPRITE_H
#define INFINITECONQUEST_SPRITE_H

#include "SFML/Graphics.hpp"
#include "Interface/Transformable.h"
#include "Interface/Drawable.h"
#include "Interface/Flippable.h"
#include "Texture.h"

class Sprite : public Drawable, public Transformable, public Flippable
{

public:
	
	Sprite();
	explicit Sprite(const Texture &texture);
	Sprite(const Texture &texture, const sf::Vector2f &size);
	Sprite(const Texture &texture, const sf::Vector2f &size, const sf::IntRect &textureRect);
	~Sprite() = default;
	
	const sf::Vector2f &getPosition() const override;
	void setPosition(float x, float y) override;
	void setPosition(const sf::Vector2f &position) override;
	
	const sf::Vector2f &getSize() const override;
	void setSize(float w, float h) override;
	void setSize(const sf::Vector2f &size) override;
	
	float getRotation() const override;
	void setRotation(float angle) override;
	
	const sf::Vector2f &getOrigin() const override;
	void setOrigin(float x, float y) override;
	void setOrigin(const sf::Vector2f &origin) override;
	
	const Texture *getTexture() const;
	void setTexture(const Texture &texture, bool resetRect = false);
	
	const sf::IntRect &getTextureRect() const;
	void setTextureRect(const sf::IntRect &textureRect);
	
	const sf::Color &getColor() const;
	void setColor(const sf::Color &color);
	
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;
	
	void flip() override;

protected:
	
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
	
	sf::Sprite sprite;
	
	// la sauvegarde la l'orgin pour le textureRect est contenu dans l'orgin de Transform
	
	sf::Vector2f textureScale;
	sf::Vector2f baseScale;
	
	sf::IntRect unflipTextureRect{};
	
	const sf::IntRect &getRealTextureRect() const;
	void setRealTextureRect(const sf::IntRect &realTextureRect);
	
	const sf::Vector2f &getTextureScale() const;
	void setTextureScale(const sf::Vector2f &textureScale);
	
	const sf::Vector2f &getBaseScale() const;
	void setBaseScale(const sf::Vector2f &baseScale);
	
	const sf::Vector2f &getScale() const override;
	void setScale(float factorX, float factorY) override;
	void setScale(const sf::Vector2f &factors) override;
	
	void updateScale();
};

#endif //INFINITECONQUEST_SPRITE_H
