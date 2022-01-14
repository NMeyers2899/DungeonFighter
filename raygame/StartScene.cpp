#include "StartScene.h"
#include "UIComponent.h"
#include "TextBox.h"

StartScene::StartScene()
{
	// Create a text box that introduces the player to the game.
	TextBox* text = new TextBox(250, 200, "Text Box");
	UIComponent* startingUI = new UIComponent(200.0f, 200.0f, 15, "Welcome to Dungeon Fighter!\n1.Start Game\n2. Quit Game");
	text->addComponent(startingUI);

	addUIElement(text);
}
