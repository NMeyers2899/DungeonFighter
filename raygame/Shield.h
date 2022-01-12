#pragma once
#include "Actor.h"
#include <Vector2.h>;

class Player;
class SpriteComponent;
class MoveComponent;
class CircleCollider;

class Shield : public Actor
{
public:
	Shield();
	Shield(Actor* owner, const char* name, float x, float y);
	~Shield();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	void onCollision(Actor* other) override;

private:
	Actor* m_owner;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_startingPosition;
	MathLibrary::Vector2 m_currentPosition;
	CircleCollider* m_collider;
	int m_timer = 0;
};
