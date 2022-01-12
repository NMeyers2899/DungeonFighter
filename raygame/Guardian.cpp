#include "Guardian.h"
#include "Engine.h"
#include "Drone.h"
#include "Transform2D.h"
#include "raylib.h"

Guardian::Guardian(float x, float y, Actor* target, int health, float scale, 
	float collisionRadius, const char* name) : Enemy(x, y, target, health, scale, 
		collisionRadius, name)
{

}

void Guardian::start()
{
	
}

void Guardian::update(float deltaTime)
{
	/*for (int i = 0; i < getTransform()->getChildCount(); i++) 
		getTransform()->getChildren()[i]->rotate(PI * deltaTime);*/

	Enemy::update(deltaTime);
}
