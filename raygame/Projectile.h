#pragma once
#include "Actor.h"
#include <Vector2.h>;

class Player;
class SpriteComponent;
class MoveComponent;

class Projectile : public Actor
{
public:
	Projectile();
	Projectile(Actor* owner, MathLibrary::Vector2 velocity, const char* name, float x, float y);
	~Projectile();

	void start() override;

private:
	Actor* m_owner;
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	
};
