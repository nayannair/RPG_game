#pragma once
#include <SFML/Graphics.hpp>


class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	sf::RectangleShape bbox;

public:

	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f getPosition();
};

