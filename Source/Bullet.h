#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utility.h"
#include "Enemy.h"

class Bullet
{
	//Member variables
private:
	std::vector<sf::CircleShape> ammo;
	sf::Vector2f enemyPosition;
	float speed;

public:
	std::vector<sf::RectangleShape> bbox;
	std::vector<sf::Vector2f> bulletDirection;
	//Member Functions
private:

public:
	Bullet();
	void Load();
	void Update(Player& playerChar, Enemy& enemy, float deltaTime);
	void Draw(sf::RenderWindow& window);

	void checkCollision(Enemy& enemyObj);

};

