#pragma once
#include "Actor.h"
#include <Vector2.h>;

class Player;
class SpriteComponent;
class MoveComponent;
class CircleCollider;

class Projectile : public Actor
{
public:
	Projectile();
	Projectile(const char* owner, MathLibrary::Vector2 velocity, const char* name, float x, float y, int charge);
	~Projectile();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	// Finds the charge of the projectile in terms of the player.
	float getCharge() { return m_charge; }

	void onCollision(Actor* other) override;

private:
	const char* m_owner;
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_startingPosition;
	MathLibrary::Vector2 m_currentPosition;
	CircleCollider* m_collider;
	float m_size = 0;
	float m_charge = 0;
};
