#include "Shield.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Engine.h"
#include "CircleCollider.h"
#include "MoveComponent.h"

Shield::Shield(Actor* owner, const char* name, float x, float y) :
	Actor(x, y, name)
{
	m_owner = owner;

	m_moveComponent = (MoveComponent*)addComponent(new MoveComponent());
	m_moveComponent->setMaxSpeed(700);

	m_startingPosition = getTransform()->getLocalPosition();
	getTransform()->setScale(MathLibrary::Vector2{ 200, 200 });
}

Shield::~Shield()
{

}

void Shield::start()
{
	m_collider = new CircleCollider(32, this);
	setCollider((Collider*)m_collider);

	Actor::start();
}

void Shield::update(float deltaTime)
{
	// Sets itself to the owner's position.
	m_currentPosition = m_owner->getTransform()->getWorldPosition();
	getTransform()->setWorldPosition(m_owner->getTransform()->getWorldPosition());

	// Once the timer runs out, it deletes itself.
	m_timer++;
	if (m_timer >= 10000)
	{
		m_timer = 0;
		Engine::destroy(this);
		return;
	}

	Actor::update(deltaTime);
}

void Shield::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Shield::onCollision(Actor* other)
{
	if (other->getName() == "EnemyShot")
	{
		MoveComponent* mc = dynamic_cast<MoveComponent*>(other->getComponent("MoveComponent"));
		mc->setVelocity((mc->getVelocity() * -1));
		other->setName("ReflectedShot");
	}
}
