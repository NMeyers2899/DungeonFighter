#pragma once
#include "Actor.h"

class InputComponent;

class TextBox : public Actor
{
public:
	TextBox() {}
	TextBox(float x, float y, const char* name) : Actor(x, y, name) {};
	~TextBox() { Actor::~Actor(); }

	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
};

