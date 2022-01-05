#pragma once
#include "Actor.h"

class InputComponent;
class MoveComponent;
class SpriteComponent;

class Player : public Actor
{
public:
	Player() {};
	Player(float x, float y, const char* name) : Actor(x, y, name) {};
	~Player() {};

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	void onCollision(Actor* other) override;

	int m_weapon = 1;
	
private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};
