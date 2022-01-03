#include "Enemy.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleCollider.h"

Enemy::Enemy(float x, float y, Actor* target)
{
	m_spriteComponent = (SpriteComponent*)addComponent(new SpriteComponent("Images/enemy.png"));
	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(250);

	getTransform()->setScale(MathLibrary::Vector2{ 50, 50 });
}

void Enemy::start()
{
	m_collider = new CircleCollider(30, this);
	setCollider((Collider*)m_collider);

	Actor::start();
}

void Enemy::update(float deltaTime)
{
}
