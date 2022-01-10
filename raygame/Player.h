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

	int getHealth() { return m_health; }

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

	void onCollision(Actor* other) override;
	
private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	int m_charge = 0;
	int m_cooldown = 0;
	int m_health = 1;
	int m_iframes = 0;
};
