#pragma once
#include "Component.h"
#include "raylib.h"

class UIComponent : public Component
{
public:
	UIComponent() {};
	UIComponent(float width, float height, int fontSize, const char* text = "", Font font = RAYLIB_H::GetFontDefault());
	~UIComponent() {};

	void draw() override;

private:
	const char* m_text;
	float m_width;
	float m_height;
	int m_fontSize;
	Font m_font;
};

