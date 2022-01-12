#pragma once
#include "Scene.h"

class Player;

class MainScene : public Scene
{
public:
	void start() override;
	void update(float deltaTime) override;
	void end() override;

private:
	Player* m_player;
	bool m_isGameOver = false;
	Actor* m_rotatingActor;
};

