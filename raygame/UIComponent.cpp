#include "UIComponent.h"
#include "Actor.h"
#include "Transform2D.h"

UIComponent::UIComponent(float width, float height, int fontSize, const char* text, Font font)
{
	m_width = width;
	m_height = height;
	m_fontSize = fontSize;
	m_font = RAYLIB_H::GetFontDefault();
	m_text = text;

	Component::Component();
}

void UIComponent::draw()
{
	// Creates a box which the text will fit in.
	Rectangle textBox = Rectangle({ getOwner()->getTransform()->getWorldPosition().x,
			getOwner()->getTransform()->getWorldPosition().y, m_width, m_height });

	// Creates the textbox.
	RAYLIB_H::DrawTextRec(m_font, m_text, textBox, m_fontSize, 1, true, RAYWHITE);
}
