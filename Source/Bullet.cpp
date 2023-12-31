#include "Bullet.h"


Bullet::Bullet()
{
	ammo.reserve(10);
    enemyPosition = sf::Vector2f(500.0f, 0.0f);
    speed = 0.005f;
}

void Bullet::Update(Player& playerChar, Enemy& enemy, float deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::CircleShape newBullet(5.0f);
        newBullet.setPosition(playerChar.getPosition() + sf::Vector2f(41.0 / 2, 36.0 / 2));
        newBullet.setFillColor(sf::Color::Red);
        newBullet.setOutlineThickness(2.0f);
        ammo.push_back(newBullet);

    }

    for (int i = 0; i < ammo.size(); i++)
    {
        sf::Vector2f bulletDirection = enemy.getPosition() - playerChar.getPosition();
        sf::Vector2f normalizedBulletDir = vectorNormalize(bulletDirection);
        ammo[i].setPosition(ammo[i].getPosition() + normalizedBulletDir * deltaTime * speed);
    }

}

void Bullet::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < ammo.size(); i++)
    {
        window.draw(ammo[i]);
    }

}