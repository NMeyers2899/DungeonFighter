#pragma once
#include "Enemy.h"

class Drone : public Enemy
{
public:
	Drone() {}
	Drone(float x, float y, Actor* target, int health, float scale, float collisionRadius, const char* name = "Enemy");
	~Drone() { Enemy::~Enemy(); }

	/// <summary>
	/// Needed to override the base enemy's update.
	/// </summary>
	void update(float deltaTime) override;
private:
};

