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

<<<<<<< Updated upstream
<<<<<<< Updated upstream
bool InputComponent::getAction1Pressed()
=======
/// <returns> Finds if the first action key has been pressed. </returns>
bool InputComponent::getWeapon1Pressed()
>>>>>>> Stashed changes
=======
/// <returns> Finds if the first action key has been pressed. </returns>
bool InputComponent::getWeapon1Pressed()
>>>>>>> Stashed changes
{
	return RAYLIB_H::IsKeyPressed(KEY_ONE);
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
bool InputComponent::getAction3Pressed()
=======
/// <returns> Finds if the third action key has been pressed. </returns>
bool InputComponent::getWeapon2Pressed()
>>>>>>> Stashed changes
{
	return IsKeyPressed(KEY_E);
}

<<<<<<< Updated upstream
bool InputComponent::getAction4Pressed()
=======
/// <returns> Finds if the fourth action key has been pressed. </returns>
bool InputComponent::getWeapon3Pressed()
>>>>>>> Stashed changes
=======
/// <returns> Finds if the first action key has been pressed. </returns>
bool InputComponent::getWeapon2Pressed()
>>>>>>> Stashed changes
{
	return RAYLIB_H::IsKeyPressed(KEY_TWO);
}

<<<<<<< Updated upstream
<<<<<<< Updated upstream
bool InputComponent::getAction1Down()
=======
/// <returns> Finds if the first action key is pressed. </returns>
bool InputComponent::getActionPressed()
>>>>>>> Stashed changes
{
	return IsKeyPressed(KEY_SPACE);
=======
/// <returns> Finds if the first action key has been pressed. </returns>
bool InputComponent::getWeapon3Pressed()
{
	return RAYLIB_H::IsKeyPressed(KEY_THREE);
>>>>>>> Stashed changes
}
<<<<<<< Updated upstream

<<<<<<< Updated upstream
bool InputComponent::getAction3Down()
=======
/// <returns> Finds if the first action key is being held down. </returns>
bool InputComponent::getActionDown()
>>>>>>> Stashed changes
{
	return IsKeyDown(KEY_SPACE);
}

<<<<<<< Updated upstream
bool InputComponent::getAction4Down()
=======
/// <returns> Finds if the first action key has been pressed. </returns>
bool InputComponent::getActionPressed()
{
	return RAYLIB_H::IsKeyPressed(KEY_F);
}

/// <returns> Finds if the first action key is being held down. </returns>
bool InputComponent::getActionDown()
>>>>>>> Stashed changes
{
	return IsKeyDown(KEY_F);
}
=======
>>>>>>> Stashed changes



