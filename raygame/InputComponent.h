#pragma once
#include "Component.h"
#include <raylib.h>
#include <Vector2.h>

class InputComponent : public Component
{
public:
	InputComponent(const char* name = "InputComponent") : Component::Component(name) {}

	// Gets the movement of the player.
	MathLibrary::Vector2 getMoveAxis();
	MathLibrary::Vector2 getLookAxis();

	// Possible actions regarding the action keys.
	bool getActionPressed();
	bool getAction2Pressed();

	bool getActionDown();


private:
	// Key for the player putting up their shield.
	RAYLIB_H::KeyboardKey m_actionKey = RAYLIB_H::KeyboardKey::KEY_F;
	RAYLIB_H::KeyboardKey m_action2Key = RAYLIB_H::KeyboardKey::KEY_Q;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};

