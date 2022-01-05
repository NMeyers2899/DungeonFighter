#include "InputComponent.h"

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	// Get the direction for the individual axis.
	float moveDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	float moveDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	// Return a new vector representing the move direction.
	return MathLibrary::Vector2(moveDirectionX, moveDirectionY);
}
MathLibrary::Vector2 InputComponent::getLookAxis()
{
	// Get the direction for the individual axis.
	float lookDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_LEFT) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_RIGHT);
	float lookDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_UP) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_DOWN);

	// Return a new vector representing the move direction.
	return MathLibrary::Vector2(lookDirectionX, lookDirectionY);
}

/// <returns> Finds if the action key has been pressed. </returns>
bool InputComponent::getActionPressed()
{
	return RAYLIB_H::IsKeyPressed(KEY_F);
}

/// <returns> Finds if the first weapon key has been pressed. </returns>
bool InputComponent::getWeapon1Pressed()
{
	return IsKeyPressed(KEY_ONE);
}

/// <returns> Finds if the second weapon key has been pressed. </returns>
bool InputComponent::getWeapon2Pressed()
{
	return IsKeyPressed(KEY_TWO);
}

/// <returns> Finds if the third weapon key has been pressed. </returns>
bool InputComponent::getWeapon3Pressed()
{
	return IsKeyPressed(KEY_THREE);
}

/// <returns> Finds if the action key is being held down. </returns>
bool InputComponent::getActionDown()
{
	return IsKeyDown(KEY_F);
}



