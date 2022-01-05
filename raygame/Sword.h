#pragma once
#include "Actor.h"
#include <Vector2.h>;

class Player;
class SpriteComponent;
class MoveComponent;
class AABBCollider;

class Sword : public Actor
{
public:
	Sword();
	Sword(Actor* owner, MathLibrary::Vector2 velocity, const char* name, float x, float y);
	~Sword();

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

private:
	Actor* m_owner;
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_startingPosition;
	MathLibrary::Vector2 m_currentPosition;
	AABBCollider* m_collider;
	Transform2D* Transform;
};
