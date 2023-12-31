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
public:
	Bullet();
	void Load();
	void Update(Player& playerChar, Enemy& enemy);
	void Draw(sf::RenderWindow& window);
};

