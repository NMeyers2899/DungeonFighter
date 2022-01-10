#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "MainScene.h"
#include "Player.h"
#include "CircleCollider.h"
#include "Geist.h"
#include "AABBCollider.h"
#include "Mothership.h"
#include "Engine.h"

void MainScene::start()
{
	m_player = new Player(50, 50, "Player");
	m_player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCol = new CircleCollider(20, m_player);
	m_player->setCollider(playerCol);

	Enemy* enemy1 = new Enemy(400, 600, m_player, 4, 50, 30);
	Geist* geist1 = new Geist(700, 200, m_player, 1, 50, 25);
	Enemy* enemy2 = new Enemy(-20, -20, m_player, 4, 50, 30);
	Mothership* mothership1 = new Mothership(200, 750, m_player, 20, 100, 60);
	Enemy* enemy3 = new Enemy(-200, 700, m_player, 4, 50, 30);
	Enemy* enemy4 = new Enemy(-100, -200, m_player, 4, 50, 30);
	Enemy* enemy5 = new Enemy(860, 400, m_player, 4, 50, 30);
	Geist* geist2 = new Geist(1000, -800, m_player, 1, 50, 25);

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
	/*addActor(geist1);
	addActor(geist2);
	addActor(enemy2);
	addActor(enemy3);
	addActor(enemy4);
	addActor(enemy5);
	addActor(mothership1);
	addActor(wall);
	addActor(wall2);*/

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
