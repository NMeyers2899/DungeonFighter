#include "Geist.h"
#include "Engine.h"
#include "Transform2D.h"
#include "Projectile.h"
#include <ctime>

void Geist::start()
{
	m_startTime = 0;

	Enemy::start();
}

void Geist::update(float deltaTime)
{
	m_timeBetweenShots = clock();

	if (m_timeBetweenShots - m_startTime > 4000)
	{
		Scene* currentScene = Engine::getCurrentScene();
		currentScene->addActor(new Projectile(this, getTransform()->getForward(), "EnemyShot",
			getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, 0));

		m_startTime = m_timeBetweenShots;
	}

	Enemy::update(deltaTime);
}

void Geist::onCollision(Actor* other)
{

}
