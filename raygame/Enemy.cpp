#include "Enemy.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "Engine.h"

Enemy::Enemy(float x, float y, Actor* target)
{
	m_target = target;

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
	MathLibrary::Vector2 moveDirection = ((m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized());

	m_moveComponent->setVelocity(moveDirection * 50);
	getTransform()->setForward(m_moveComponent->getVelocity());

	Actor::update(deltaTime);
}

void Enemy::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Enemy::onCollision(Actor* other)
{
	if (other->getName() == "Arrow")
	{
		Engine::destroy(this);
		Engine::destroy(other);
	}
}


