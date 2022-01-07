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

	Enemy* enemy = new Enemy(400, 600, player, 10, 50, 30);
	Geist* enemy1 = new Geist(700, 200, player, 3, 50, 30);
	Enemy* enemy2 = new Enemy(-20, -20, player, 3, 50, 20);
	Mothership* enemy3 = new Mothership(200, 750, player, 20, 100, 60);

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
	addActor(enemy);
	addActor(enemy1);
	addActor(enemy2);
	addActor(enemy3);
	addActor(wall);
	addActor(wall2);
}
