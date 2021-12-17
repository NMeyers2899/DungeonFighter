#include "Projectile.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Engine.h"

Projectile::Projectile(Actor* owner, MathLibrary::Vector2 velocity, const char* name, float x, float y) : Actor(x, y, name)
{
	m_owner = owner;
	m_velocity = velocity;

	m_spriteComponent = (SpriteComponent*)addComponent(new SpriteComponent("Images/bullet.png"));
	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(500);

	getTransform()->setScale(MathLibrary::Vector2{ 50, 50 });
}

Projectile::~Projectile()
{
	Engine::getCurrentScene()->removeActor(this);
}

void Projectile::start()
{
	m_moveComponent->setVelocity(m_velocity * 500);

	Actor::start();
}
