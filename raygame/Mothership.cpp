#include "Mothership.h"
#include "Scene.h"
#include "Engine.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include <ctime>

void Mothership::start()
{
	m_startingTime = 0;

	Enemy::start();
}

void Mothership::update(float deltaTime)
{
	m_timeBetweenSpawns = clock();

	if (m_timeBetweenSpawns - m_startingTime > 10000)
	{
		Scene* currentScene = Engine::getCurrentScene();
		currentScene->addActor(new Enemy(getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y,
			Engine::getCurrentScene()->getActor(0), 2, 25, 18));

		m_startingTime = m_timeBetweenSpawns;
	}
}

void Mothership::onCollision(Actor* other)
{
	if (other->getName() == "Arrow")
	{
		// Destroy the projectile.
		Engine::destroy(other);

		setHealth(getHealth() - 1);

		// If health is less than or equal to zero, destroy this actor.
		if (getHealth() <= 0)
			Engine::destroy(this);
	}

	if (other->getName() == "Wall")
		getTransform()->setWorldPosition(getTransform()->getWorldPosition() - getMoveComponent()->getVelocity().getNormalized());
}
