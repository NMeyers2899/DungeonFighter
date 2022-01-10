#include "StartScene.h"
#include "UIComponent.h"
#include "TextBox.h"

void StartScene::start()
{
	if (getActors().getLength() <= 1)
	{
		TextBox* text = new TextBox(250, 200, "Text Box");
		UIComponent* startingUI = new UIComponent(200.0f, 200.0f, 15, "Welcome to Dungeon Fighter!\n1.Start Game\n2. Quit Game");
		text->addComponent(startingUI);

		addUIElement(text);
	}

	Scene::start();
}

void StartScene::end()
{
	//Calls end for all actors in the array
	for (int i = 0; i < getActors().getLength(); i++)
	{
		if (getActors().getActor(i)->getStarted())
			getActors().getActor(i)->end();
	}
}
