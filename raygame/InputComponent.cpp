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
bool InputComponent::getAction1Pressed()
{
	return RAYLIB_H::IsKeyPressed(KEY_SPACE);
}

/// <returns> Finds if the third action key has been pressed. </returns>
bool InputComponent::getAction3Pressed()
{
	return IsKeyPressed(KEY_E);
}

/// <returns> Finds if the fourth action key has been pressed. </returns>
bool InputComponent::getAction4Pressed()
{
	return IsKeyPressed(KEY_F);
}

/// <returns> Finds if the first action key is being held down. </returns>
bool InputComponent::getAction1Down()
{
	return IsKeyDown(KEY_SPACE);
}

/// <returns> Finds if the third action key is being held down. </returns>
bool InputComponent::getAction3Down()
{
	return IsKeyDown(KEY_E);
}

/// <returns> Finds if the fourth action key is being held down. </returns>
bool InputComponent::getAction4Down()
{
	return IsKeyDown(KEY_F);
}


