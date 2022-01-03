#pragma once
#include "Actor.h"

class MoveComponent;
class SpriteComponent;
class CircleCollider;

class Enemy : public Actor
{
public:
	Enemy();
	Enemy(float x, float y);
	~Enemy();

	void update(float deltaTime) override;

	void onCollision(Actor* other) override;

private:
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	CircleCollider* m_collider;
};

