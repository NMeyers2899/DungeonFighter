#include "TextBox.h"
#include "InputComponent.h"
#include "Engine.h"
#include "SpriteComponent.h"

TextBox::TextBox(float x, float y, const char* name, const char* path) : Actor(x, y, name)
{
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent(path)));
}

void TextBox::start()
{
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
}

void TextBox::update(float deltaTime)
{
	// Use the inputs to allow the player to start the game or quit the game.
	if (m_inputComponent->get1KeyPressed())
		Engine::setCurrentScene(1);

	if (m_inputComponent->get2KeyPressed())
		Engine::CloseApplication();
}
