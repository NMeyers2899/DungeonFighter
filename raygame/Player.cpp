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
#include "Sword.h"
#include "Collider.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(100);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));


	// Set spawn point.
	// Set move speed.
	// Set position clamps.
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();
	MathLibrary::Vector2 lookDirection = m_inputComponent->getLookAxis();

	m_moveComponent->setVelocity(moveDirection * 100);

	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());
	if (lookDirection.getMagnitude() > 0)
		getTransform()->setForward(lookDirection.getNormalized());
	if (m_inputComponent->getWeapon1Pressed())
		m_weapon = 1;
	if (m_inputComponent->getWeapon2Pressed())
		m_weapon = 2;
	if (m_inputComponent->getWeapon3Pressed())
		m_weapon = 3;

	if (m_inputComponent->getActionPressed()) 
	{
		Scene* currentScene = Engine::getCurrentScene();
		if (m_weapon == 1) 
		{
			currentScene->addActor(new Projectile(this, getTransform()->getForward(), "Attack",
				getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y));
		}
		if (m_weapon == 2)
		{
			Sword* sword = new Sword(this, getTransform()->getForward(), "Attack",
				getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y);
			Transform->addChild(sword->getTransform());
			currentScene->addActor(sword);
		}
	}

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

	if (other->getName() == "Enemy")
	{
		getTransform()->setWorldPosition({ 20, 20 });
		return;
	}
}
