#pragma once
#include "Scene.h"

class InputComponent;

class StartScene : public Scene
{
public:
	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
};

