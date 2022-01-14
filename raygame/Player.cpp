#include "Player.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "raylib.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "Engine.h"
#include "Scene.h"
#include "Projectile.h"
#include "Shield.h"
#include "Collider.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(150);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();
	MathLibrary::Vector2 lookDirection = m_inputComponent->getLookAxis();

	m_moveComponent->setVelocity(moveDirection * 150);

	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());
	if (lookDirection.getMagnitude() > 0)
		getTransform()->setForward(lookDirection.getNormalized());

	// Clamping the player's position.
	if(getTransform()->getWorldPosition().x <= 0 || 
		getTransform()->getWorldPosition().x >= 700 || 
		getTransform()->getWorldPosition().y <= 0 || 
		getTransform()->getWorldPosition().y >= 800)
		getTransform()->setWorldPosition(getTransform()->getWorldPosition() - m_moveComponent->getVelocity().getNormalized());

	if (m_inputComponent->getActionDown()) 
	{
		m_charge++;
		if (m_charge > 1000)
			m_charge = 1000;
	}
	if (m_inputComponent->getActionDown() == false && m_charge != 0)
	{
		Scene* currentScene = Engine::getCurrentScene();
		currentScene->addActor(new Projectile(this->getName(), getTransform()->getForward(), "Arrow", 
			getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y, m_charge));
		m_charge = 0;
	}
	if (m_inputComponent->getAction2Pressed() && m_cooldown == 0) 
	{
		m_cooldown = 20000;
		Scene* currentScene = Engine::getCurrentScene();
		currentScene->addActor(new Shield(this, "Shield",
			getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y));
	}
	if (m_cooldown >= 1)
		m_cooldown--;

	Actor::update(deltaTime);
}

void Player::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Player::onCollision(Actor* other)
{
	if (other->getName() == "Wall")
		getTransform()->setWorldPosition(getTransform()->getWorldPosition() - m_moveComponent->getVelocity().getNormalized());

	if (other->getName() == "Basic" || other->getName() == "Geist" 
		|| other->getName() == "Guardian" || other->getName() == "Drone" 
		|| other->getName() == "Mothership")
	{
		m_health--;
		return;
	}

	if (other->getName() == "EnemyShot")
	{
		Engine::destroy(other);
		m_health--;
		return;
	}
}
