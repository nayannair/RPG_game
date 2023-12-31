#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utility.h"
#include "Enemy.h"

class Bullet
{
private:
	std::vector<sf::CircleShape> ammo;
	sf::Vector2f enemyPosition;
	float speed;
	sf::RectangleShape bbox;

public:
	Bullet();
	void Load();
	void Update(Player& playerChar, Enemy& enemy, float deltaTime);
	void Draw(sf::RenderWindow& window);
};

