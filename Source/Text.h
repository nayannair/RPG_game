#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Text
{
private:

protected:
	sf::Text componentText;
	sf::Font componentFont;

public:

	virtual void Load();
	virtual void Update();
	virtual void Draw(sf::RenderWindow& window);
};

