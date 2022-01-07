#pragma once
#include "Enemy.h"

class Geist : public Enemy
{
public:
	Geist() {};
	Geist(float x, float y, Actor* target, int health, float scale, float collisionRadius, const char* name = "Enemy") 
		: Enemy(x, y, target, health, scale, collisionRadius, name) {};
	~Geist() {};

	void start() override;
	void update(float deltaTime) override;
	void onCollision(Actor* other) override;

private:
	float m_startTime;
	float m_timeBetweenShots;
};

