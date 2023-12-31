#pragma once
#include <SFML/Graphics.hpp>


class Enemy
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:


	void Load();
	void Update();
	void Draw(sf::RenderWindow& window);

	sf::Vector2f getPosition();
};


