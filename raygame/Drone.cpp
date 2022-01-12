#include "Drone.h"

Drone::Drone(float x, float y, Actor* target, int health, float scale, 
	float collisionRadius, const char* name) : Enemy(x, y, target, health, scale,
		collisionRadius, name)
{

}

void Drone::update(float deltaTime)
{
	
}
