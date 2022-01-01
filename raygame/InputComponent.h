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

	// Possible actions regarding the action keys.
	bool getAction1Pressed();
	bool getAction3Pressed();
	bool getAction4Pressed();

	bool getAction1Down();
	bool getAction3Down();
	bool getAction4Down();

private:
	// Key for the player putting up their shield.
	RAYLIB_H::KeyboardKey m_action1Key = RAYLIB_H::KeyboardKey::KEY_SPACE;
	RAYLIB_H::KeyboardKey m_action2Key = RAYLIB_H::KeyboardKey::KEY_P;
	// Key for the player swining their sword.
	RAYLIB_H::KeyboardKey m_action3Key = RAYLIB_H::KeyboardKey::KEY_E;
	// Key for the player firing their bow.
	RAYLIB_H::KeyboardKey m_action4Key = RAYLIB_H::KeyboardKey::KEY_F;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};
