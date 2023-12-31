#pragma once
#include <SFML/Graphics.hpp>


class Enemy
{
	//Member variables
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	sf::RectangleShape bbox;

	//Member functions
private:
public:

	void Initialize();
	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);

	sf::Vector2f getPosition();
};


