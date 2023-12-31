#include "Text.h"
#include <iostream>

void Text::Load()
{
	if (componentFont.loadFromFile("Assets/Fonts/EagleLake-Regular.ttf"))
	{
		std::cout << "Font loaded succesfully from file\n";
		componentText.setFont(componentFont);

	}
	else
	{
		std::cout << "Font failed to load!\n";
	}

}

void Text::Update()
{
}

void Text::Draw(sf::RenderWindow& window )
{
	window.draw(componentText);
}

