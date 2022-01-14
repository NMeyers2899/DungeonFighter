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

/// <returns> Finds if the first action key has been pressed. </returns>
bool InputComponent::getActionPressed()
{
	return RAYLIB_H::IsKeyPressed(KEY_SPACE);
}

/// <returns> Finds if the second action key has been pressed. </returns>
bool InputComponent::getAction2Pressed()
{
	return IsKeyPressed(KEY_Q);
}

/// <returns> Finds if the first action key is being held down. </returns>
bool InputComponent::getActionDown()
{
	return IsKeyDown(KEY_SPACE);
}

bool InputComponent::get1KeyPressed()
{
	return IsKeyPressed(KEY_ONE);
}

bool InputComponent::get2KeyPressed()
{
	return IsKeyPressed(KEY_TWO);
}


