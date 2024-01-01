#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utility.h"
#include "Enemy.h"
#include <iostream>

class Bullet
{
	//Member variables
private:
	sf::CircleShape bulletSprite;
	sf::Vector2f enemyPosition;
	float speed;
	sf::RectangleShape bbox;
	sf::Vector2f bulletDirection;

public:

	//Member Functions
private:

public:
	Bullet();
	void Load();
	void Update(float deltaTime);
	const sf::CircleShape& Draw();
	void setDirection(sf::Vector2f& bulletDir);
	void setPosition(sf::Vector2f& bulletPos);
    const sf::FloatRect& getGlobalBounds();
	const sf::Vector2f& getPosition();
};

