#include "Geist.h"
#include "Engine.h"
#include "Transform2D.h"
#include "Projectile.h"
#include <ctime>

Geist::~Geist()
{
	Enemy::~Enemy();
}

void Geist::start()
{
	m_startTime = 0;

	Enemy::start();
}

void Geist::update(float deltaTime)
{
	m_timeBetweenShots = clock();

	// Checks to see how long it should take to shoot.
	if (m_timeBetweenShots - m_startTime > 4000)
	{
		Scene* currentScene = Engine::getCurrentScene();
		currentScene->addActor(new Projectile(this->getName(), getTransform()->getForward(), "EnemyShot",
			getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, 0));

		m_startTime = m_timeBetweenShots;
	}

	Enemy::update(deltaTime);
}

void Geist::onCollision(Actor* other)
{
	if (other->getName() == "ReflectedShot")
	{
		Engine::destroy(other);

		setHealth(getHealth() - 1);

		if (getHealth() <= 0)
			Engine::destroy(this);
	}
}
