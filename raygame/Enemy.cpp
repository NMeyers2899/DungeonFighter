#include "Enemy.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Projectile.h"

Enemy::Enemy(float x, float y, Actor* target, int health, float scale, float collisionRadius, const char* name) 
	: Actor(x, y, name)
{
	m_target = target;
	m_health = health;

	m_spriteComponent = (SpriteComponent*)addComponent(new SpriteComponent("Images/enemy.png"));
	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(100);

	getTransform()->setScale(MathLibrary::Vector2{ scale, scale });

	m_collider = new CircleCollider(collisionRadius, this);
	setCollider((Collider*)m_collider);
}

void Enemy::update(float deltaTime)
{
	// Gets the distance between the target and this actor.
	MathLibrary::Vector2 moveDirection = ((m_target->getTransform()->getWorldPosition() - getTransform()->getWorldPosition()).getNormalized());

	// Sets the actor on a movement path towards its target.
	m_moveComponent->setVelocity(moveDirection * 70);
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
		Projectile* proj = dynamic_cast<Projectile*>(other);
		// Destroy the projectile.
		Engine::destroy(other);
		if(proj->getCharge() <= 250)
			m_health--;
		if (proj->getCharge() <= 500)
			m_health -= 2;
		if (proj->getCharge() == 1000)
			m_health -= 3;

		// If health is less than or equal to zero, destroy this actor.
		if (m_health <= 0)
			Engine::destroy(this);
	}

	if (other->getName() == "Wall")
		getTransform()->setWorldPosition(getTransform()->getWorldPosition() - m_moveComponent->getVelocity().getNormalized());
	if (other->getName() == "Shield")
		getTransform()->setWorldPosition(getTransform()->getWorldPosition() - m_moveComponent->getVelocity().getNormalized());
}


