#pragma once
#include "Enemy.h"

class Guardian : public Enemy
{
public:
	Guardian() {}
	Guardian(float x, float y, Actor* target, int health, float scale, float collisionRadius, const char* name = "Enemy");
	~Guardian() { Enemy::~Enemy(); }

	void start() override;
	void update(float deltaTime) override;
private:
};

