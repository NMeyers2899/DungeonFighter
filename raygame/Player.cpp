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

void Player::start()
{
	Actor::start();

	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*>(addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(500);
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));


	// Set spawn point.
	// Set move speed.
	// Set position clamps.
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * 300);

	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());

	if (m_inputComponent->getAction4Pressed()) 
	{
		Scene* currentScene = Engine::getCurrentScene();
		currentScene->addActor(new Projectile(this, getTransform()->getForward(), "Arrow", 
			getTransform()->getWorldPosition().x, getTransform()->getWorldPosition().y));
	}

	Actor::update(deltaTime);
}
