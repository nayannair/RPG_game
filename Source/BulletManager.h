#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utility.h"
#include "Enemy.h"
#include "Bullet.h"


class BulletManager
{
private:
	std::vector<Bullet> ammo;
	float fireRate;
	float fireTimer;
public:
	void Load();
	void Update(Player& playerChar, sf::Vector2f& mousePos, Enemy& enemy, float deltaTime);
	void Draw(sf::RenderWindow& window);
	void checkCollision(Enemy& enemyObj);
	void checkBounds();
};

