#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	ammo.reserve(10);
    enemyPosition = sf::Vector2f(500.0f, 0.0f);
    speed = 0.0005f;

    bbox.reserve(10);
    bulletDirection.reserve(10);
    
}

void Bullet::Update(Player& playerChar, Enemy& enemy, float deltaTime)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::CircleShape newBullet(5.0f);
        newBullet.setPosition(playerChar.getPosition() + sf::Vector2f(41.0 / 2, 36.0 / 2));
        newBullet.setFillColor(sf::Color::Red);
        ammo.push_back(newBullet);

        sf::RectangleShape newBbox(sf::Vector2f(5.0f, 5.0f));
        newBbox.setOutlineThickness(2.0f);
        newBbox.setOutlineColor(sf::Color::White);
        newBbox.setFillColor(sf::Color::Transparent);
        newBbox.setSize(sf::Vector2f(5.0f, 5.0f));
        bbox.push_back(newBbox);

        sf::Vector2f newBulletDir = enemy.getPosition() - playerChar.getPosition();
        bulletDirection.push_back(newBulletDir);
    }

    for (int i = 0; i < ammo.size(); i++)
    {
        sf::Vector2f normalizedBulletDir = vectorNormalize(bulletDirection[i]);
        ammo[i].setPosition(ammo[i].getPosition() + normalizedBulletDir * deltaTime * speed);
        bbox[i].setPosition(ammo[i].getPosition());
    }

    //Check Collision for bullets
    this->checkCollision(enemy);

}

void Bullet::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < ammo.size(); i++)
    {
        window.draw(ammo[i]);
    }

}

void Bullet::checkCollision(Enemy& enemyObj)
{
    sf::FloatRect enemyBound = enemyObj.bbox.getGlobalBounds();
    
    for (int i = 0; i < ammo.size(); i++)
    {
        sf::FloatRect bulletBound = bbox[i].getGlobalBounds();

        if (enemyBound.intersects(bulletBound))
        {
            std::cout << "Bullet collided with enemy!!\n";
          
            //Delete bullet from ammo, its corresponding bbox and bullet directio
            std::swap(ammo[i], ammo[ammo.size() - 1]);
            ammo.pop_back();
            std::swap(bbox[i], bbox[bbox.size() - 1]);
            bbox.pop_back();
            std::swap(bulletDirection[i], bulletDirection[bulletDirection.size() - 1]);
            bulletDirection.pop_back();
            i--;


        }
        else
        {
            //std::cout << "Bullet shooting through empty space...\n";
        }
    }
    
}