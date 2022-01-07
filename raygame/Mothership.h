#pragma once
#include "Enemy.h"
#include <iostream>

class Mothership : public Enemy
{
public:
	Mothership() {};
	Mothership(float x, float y, Actor* target, int health, float scale, float collisionRadius, const char* name = "Enemy") 
		: Enemy(x, y, target, health, scale, collisionRadius, name) {};
	~Mothership() {};

	void start() override;
	void update(float deltaTime) override;

	void onCollision(Actor* other) override;

private:
	float m_startingTime;
	float m_timeBetweenSpawns;
};

