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
	bool getWeapon1Pressed();
	bool getWeapon2Pressed();
	bool getWeapon3Pressed();
<<<<<<< Updated upstream

	bool getActionPressed();
	bool getActionDown();

private:
	//Weapon Switching Keys
	RAYLIB_H::KeyboardKey m_weapon1Key = RAYLIB_H::KeyboardKey::KEY_ONE;
	RAYLIB_H::KeyboardKey m_weapon2Key = RAYLIB_H::KeyboardKey::KEY_TWO;
	RAYLIB_H::KeyboardKey m_weapon3Key = RAYLIB_H::KeyboardKey::KEY_THREE;
	// Weapon attack key
	RAYLIB_H::KeyboardKey m_actionKey = RAYLIB_H::KeyboardKey::KEY_SPACE;
=======
	bool getActionPressed();

	bool getActionDown();

private:
	// Key for the player putting up their shield.
	RAYLIB_H::KeyboardKey m_weapon1Key = RAYLIB_H::KeyboardKey::KEY_ONE;
	RAYLIB_H::KeyboardKey m_weapon2Key = RAYLIB_H::KeyboardKey::KEY_TWO;
	RAYLIB_H::KeyboardKey m_weapon3Key = RAYLIB_H::KeyboardKey::KEY_THREE;
	RAYLIB_H::KeyboardKey m_actionKey = RAYLIB_H::KeyboardKey::KEY_F;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
>>>>>>> Stashed changes
};

