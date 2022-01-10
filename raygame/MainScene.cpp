#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "MainScene.h"
#include "Player.h"
#include "CircleCollider.h"
#include "Geist.h"
#include "AABBCollider.h"
#include "Mothership.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCol = new CircleCollider(20, player);
	player->setCollider(playerCol);

	Enemy* enemy1 = new Enemy(400, 600, player, 4, 50, 30);
	Geist* geist1 = new Geist(700, 200, player, 1, 50, 25);
	Enemy* enemy2 = new Enemy(-20, -20, player, 4, 50, 30);
	Mothership* mothership1 = new Mothership(200, 750, player, 20, 100, 60);
	Enemy* enemy3 = new Enemy(-200, 700, player, 4, 50, 30);
	Enemy* enemy4 = new Enemy(-100, -200, player, 4, 50, 30);
	Enemy* enemy5 = new Enemy(860, 400, player, 4, 50, 30);
	Geist* geist2 = new Geist(1000, -800, player, 1, 50, 25);

	Actor* wall = new Actor(400, 600, "Wall");
	wall->getTransform()->setScale({ 50, 100 });
	AABBCollider* wallCol = new AABBCollider(wall);
	wall->setCollider(wallCol);
	Actor* wall2 = new Actor(200, 400, "Wall");
	wall2->getTransform()->setScale({ 50, 100 });
	AABBCollider* wall2Col = new AABBCollider(wall2);
	wall2->setCollider(wall2Col);

	// All starting actors.
	addActor(player);
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

	Scene::Scene();
}
