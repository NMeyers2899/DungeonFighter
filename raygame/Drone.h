#pragma once
#include "Enemy.h"

class Drone : public Enemy
{
public:
	Drone() {}
	Drone(float x, float y, Actor* target, int health, float scale, float collisionRadius, const char* name = "Enemy");
	~Drone() { Enemy::~Enemy(); }

	void update(float deltaTime) override;
private:
};

