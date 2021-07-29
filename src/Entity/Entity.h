//
// Created by Elyas EL IDRISSI on 28/02/2021.
//

#ifndef INFINITECONQUEST_ENTITY_H
#define INFINITECONQUEST_ENTITY_H

#include <SFML/Graphics.hpp>

#include "Library/hashmap.h"
#include "Sprite/SpriteSheet.h"
#include "Interface/Transformable.h"
#include "Interface/Drawable.h"
#include "Entity/EntityTeam.h"
#include "Entity/EntityType.h"
#include "Entity/EntityState.h"
#include "Game/GameEntityRole.h"

class Entity : public Drawable, public Transformable, public Flippable, public EntityTeam, public EntityType, public EntityState
{

public :
	
	virtual ~Entity() = default;
	
	bool isIdling() const;
	void idle(bool force = false);
	
	bool isAttacking() const;
	virtual void generateAttack(Entity &target) = 0;
	virtual int attack(Entity &target, bool visualOnly = false, bool force = false);
	
	bool isRunning() const;
	void run(bool force = false);
	
	bool isDying() const;
	void die(bool force = false);
	
	bool isAlive() const;
	bool isDead() const;
	
	const std::string &getEntityId() const;
	void setEntityId(const std::string &entityId);
	
	const std::string &getEntityName() const;
	void setEntityName(const std::string &entityName);
	
	GameEntityRole::Role getRole() const;
	Entity & setRole(GameEntityRole::Role role);
	
	Team getTeam() const;
	Entity * setTeam(Team team);
	
	Type getType() const;
	void setType(Type type);
	
	State getState() const;
	void setState(State state);
	
	int getAttackDamage() const;
	void setAttackDamage(int atkDamage);
	
	int getLifePointMax() const;
	void setLifePointMax(int lifePointMax);
	
	int getLifePoint() const;
	void setLifePoint(int lifePoint);
	
	const SpriteSheet &getSprite() const;
	SpriteSheet &getSprite();
	const SpriteSheet &getSprite(const std::string &spriteId) const;
	SpriteSheet &getSprite(const std::string &spriteId);
	void setSprite(const std::string &spriteId, const SpriteSheet &sprite);
	
	const sf::Vector2f &getPosition() const override;
	void setPosition(float x, float y) override;
	void setPosition(const sf::Vector2f &position) override;
	
	float getRotation() const override;
	void setRotation(float angle) override;
	
	const sf::Vector2f &getOrigin() const override;
	void setOrigin(float x, float y) override;
	void setOrigin(const sf::Vector2f &origin) override;
	
	void flip() override;
	void flip(Flippable::Side side) override;
	
protected:
	
	Entity() = default;
	
	Entity(const std::string &entityId, const std::string &entityName, Team team, Type type, const sf::Vector2f &size, int lifePointMax, int atkDamage);
	
	std::string entityId;
	
	std::string entityName;
	
	GameEntityRole::Role role = GameEntityRole::ENTITYROLE_PLAYER;
	
	Team team = TEAM_PLAYER;
	
	Type type = TYPE_PLAYER;
	
	State state = State::IDLE;
	
	hashmap::unordered_map<std::string, SpriteSheet> sprites{};
	
	int atkDamage = 0;
	
	int lifePointMax = 0;
	
	int lifePoint = 0;
	
	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //INFINITECONQUEST_ENTITY_H
