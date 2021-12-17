#include "InputComponent.h"

MathLibrary::Vector2 InputComponent::getMoveAxis()
{
	// Get the direction for the individual axis.
	float moveDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_A) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_D);
	float moveDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_W) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_S);

	// Return a new vector representing the move direction.
	return MathLibrary::Vector2(moveDirectionX, moveDirectionY);
}

bool InputComponent::getAction1Pressed()
{
	return RAYLIB_H::IsKeyPressed(KEY_SPACE);
}

bool InputComponent::getAction3Pressed()
{
	return IsKeyPressed(KEY_E);
}

bool InputComponent::getAction4Pressed()
{
	return IsKeyPressed(KEY_F);
}

bool InputComponent::getAction1Down()
{
	return IsKeyDown(KEY_SPACE);
}

bool InputComponent::getAction3Down()
{
	return IsKeyDown(KEY_E);
}

bool InputComponent::getAction4Down()
{
	return IsKeyDown(KEY_F);
}


