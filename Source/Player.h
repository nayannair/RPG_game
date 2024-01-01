#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Player
{
	//Member Variables
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
	
public:
	sf::RectangleShape bbox;

	//Member Functions
private:

public:

	void Initialize();
	void Load();
	void Update(float deltaTime, Enemy &enemyObj);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f getPosition();
	void checkCollision(Enemy& enemyObj);
	
};

