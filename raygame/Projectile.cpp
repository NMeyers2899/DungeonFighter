#include "Projectile.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Engine.h"
#include "CircleCollider.h"

Projectile::Projectile(const char* owner, MathLibrary::Vector2 velocity, const char* name, float x, float y, int charge) : 
	Actor(x, y, name)
{
	m_owner = owner;
	m_velocity = velocity;

	m_spriteComponent = (SpriteComponent*)addComponent(new SpriteComponent("Images/bullet.png"));
	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(700);

	m_startingPosition = getTransform()->getLocalPosition();

	m_charge = charge;

	m_size = 50 + (charge/10);
	getTransform()->setScale(MathLibrary::Vector2{ m_size, m_size });
}

Projectile::~Projectile()
{
	Actor::~Actor();
}

void Projectile::start()
{
	m_moveComponent->setVelocity(m_velocity * 700);

	m_size = 8 + (m_charge / 50);
	m_collider = new CircleCollider(m_size, this);
	setCollider((Collider*)m_collider);

	Actor::start();
}

void Projectile::update(float deltaTime) 
{
	m_currentPosition = getTransform()->getLocalPosition();

	MathLibrary::Vector2 displacement = m_currentPosition - m_startingPosition;
	float distance = displacement.getMagnitude();

	float dist = 200 + (m_charge/5);
	if (distance >= dist)
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

void Projectile::onCollision(Actor* other)
{
	if (other->getName() == "Wall")
		Engine::destroy(this);
}
