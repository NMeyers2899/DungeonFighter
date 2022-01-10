#pragma once
#include "Actor.h"

class InputComponent;
class SpriteComponent;

class TextBox : public Actor
{
public:
	TextBox() {}
	TextBox(float x, float y, const char* name, const char* path = "");
	~TextBox() { Actor::~Actor(); }

	void start() override;
	void update(float deltaTime) override;

private:
	InputComponent* m_inputComponent;
	SpriteComponent* m_spriteComponent;
};

