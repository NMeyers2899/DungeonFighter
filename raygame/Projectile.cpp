#include "Projectile.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Engine.h"
#include "CircleCollider.h"

Projectile::Projectile(Actor* owner, MathLibrary::Vector2 velocity, const char* name, float x, float y) : 
	Actor(x, y, name)
{
	m_owner = owner;
	m_velocity = velocity;

	m_spriteComponent = (SpriteComponent*)addComponent(new SpriteComponent("Images/bullet.png"));
	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(700);

	m_startingPosition = getTransform()->getLocalPosition();

	getTransform()->setScale(MathLibrary::Vector2{ 50, 50 });
}

Projectile::~Projectile()
{
	
}

void Projectile::start()
{
	m_moveComponent->setVelocity(m_velocity * 700);

	m_collider = new CircleCollider(8, this);
	setCollider((Collider*)m_collider);

	Actor::start();
}

void Projectile::update(float deltaTime) 
{
	m_currentPosition = getTransform()->getLocalPosition();

	MathLibrary::Vector2 displacement = m_currentPosition - m_startingPosition;
	float distance = displacement.getMagnitude();

	if (distance >= 200)
	{
		Engine::destroy(this);
		return;
	}	
		
	Actor::update(deltaTime);
}

void Projectile::draw()
{
	Actor::draw();
	getCollider()->draw();
}
