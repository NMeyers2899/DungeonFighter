#pragma once
#include "Scene.h"

class InputComponent;
class TextBox;

class StartScene : public Scene
{
public:
	void start() override;
	void end() override;
};

