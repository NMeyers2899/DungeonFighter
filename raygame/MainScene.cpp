#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "MainScene.h"
#include "Player.h"
#include "CircleCollider.h"
#include "Geist.h"
#include "AABBCollider.h"
#include "Mothership.h"
#include "Engine.h"
#include "TextBox.h"
#include "UIComponent.h"
#include "Drone.h"

void MainScene::start()
{
	m_isGameOver = false;

	// Initializing the player
	m_player = new Player(350, 400, "Player");
	m_player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCol = new CircleCollider(20, m_player);
	m_player->setCollider(playerCol);

	// Initializing enemies
	Enemy* enemy1 = new Enemy(400, 600, m_player, 4, 50, 30, "Basic");
	Geist* geist1 = new Geist(700, 200, m_player, 1, 50, 25, "Geist");
	Enemy* enemy2 = new Enemy(-20, -20, m_player, 4, 50, 30, "Basic");
	Mothership* mothership1 = new Mothership(200, 750, m_player, 20, 100, 60, "Mothership");
	Enemy* enemy3 = new Enemy(-200, 700, m_player, 4, 50, 30, "Basic");
	Enemy* enemy4 = new Enemy(-100, -200, m_player, 4, 50, 30, "Basic");
	Enemy* enemy5 = new Enemy(860, 400, m_player, 4, 50, 30, "Basic");
	Geist* geist2 = new Geist(1000, -800, m_player, 1, 50, 25, "Geist");
	Enemy* guardian1 = new Enemy(500, 500, m_player, 1, 50, 25, "Guardian");
	Drone* drone1 = new Drone(0.5, 0, nullptr, 1, 22, 14, "Drone");
	Drone* drone2 = new Drone(0, 0.5, nullptr, 1, 20, 10, "Drone");
	Drone* drone3 = new Drone(-0.5, 0, nullptr, 1, 20, 10, "Drone");
	Drone* drone4 = new Drone(0, -0.5, nullptr, 1, 20, 10, "Drone");
	guardian1->getTransform()->addChild(drone1->getTransform());
	guardian1->getTransform()->addChild(drone2->getTransform());
	guardian1->getTransform()->addChild(drone3->getTransform());
	guardian1->getTransform()->addChild(drone4->getTransform());

	// Initializing Walls
	Actor* wall = new Actor(400, 600, "Wall");
	wall->getTransform()->setScale({ 50, 100 });
	AABBCollider* wallCol = new AABBCollider(wall);
	wall->setCollider(wallCol);
	Actor* wall2 = new Actor(200, 400, "Wall");
	wall2->getTransform()->setScale({ 50, 100 });
	AABBCollider* wall2Col = new AABBCollider(wall2);
	wall2->setCollider(wall2Col);

	// All starting actors.
	addActor(m_player);
	addActor(enemy1);
	addActor(geist1);
	addActor(geist2);
	addActor(enemy2);
	addActor(enemy3);
	addActor(enemy4);
	addActor(enemy5);
	addActor(mothership1);
	addActor(wall);
	addActor(wall2);
	addActor(guardian1);

	Scene::start();
}

void MainScene::update(float deltaTime)
{
	if (!m_isGameOver && m_player->getHealth() <= 0)
	{
		for (int i = 0; i < getActors().getLength(); i++)
			Engine::destroy(getActors().getActor(i));

		Engine::setCurrentScene(0);

		m_isGameOver = true;
	}

	Scene::update(deltaTime);
}

void MainScene::end()
{
	Scene::end();
}
