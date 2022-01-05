#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "MainScene.h"
#include "Player.h"
#include "CircleCollider.h"
#include "Enemy.h"
#include "AABBCollider.h"

void MainScene::start()
{
	Player* player = new Player(50, 50, "Player");
	player->getTransform()->setScale({ 50, 50 });
	CircleCollider* playerCol = new CircleCollider(20, player);
	player->setCollider(playerCol);

	Enemy* enemy = new Enemy(400, 600, player, 100);
	Enemy* enemy1 = new Enemy(700, 200, player, 3);
	Enemy* enemy2 = new Enemy(-20, -20, player, 3);

	Actor* wall = new Actor(400, 600, "Wall");
	wall->getTransform()->setScale({ 50, 100 });
	AABBCollider* wallCol = new AABBCollider(wall);
	wall->setCollider(wallCol);

	addActor(player);
	/*addActor(enemy);
	addActor(enemy1);
	addActor(enemy2);*/
	addActor(wall);
}
