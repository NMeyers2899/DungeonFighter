#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;
class CircleCollider;

class Enemy : public Actor
{
public:
	Enemy() {};
	Enemy(float x, float y, Actor* target, int health);
	~Enemy() {};

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	void onCollision(Actor* other) override;

	int getHealth() { return m_health; }
	void setHealth(int value) { m_health = value; }

private:
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	CircleCollider* m_collider;
	Actor* m_target;
	int m_health;
};

