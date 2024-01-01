#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
    speed = 0.0005f;  
    bulletSprite.setRadius(5.0f);
    bulletSprite.setFillColor(sf::Color::Red);

    bbox.setSize(sf::Vector2f(5.0f, 5.0f));
    //bbox.setOutlineThickness(2.0f);
    //bbox.setOutlineColor(sf::Color::White);
    //bbox.setFillColor(sf::Color::Transparent);
}

void Bullet::setDirection(sf::Vector2f& bulletDir)
{
    bulletDirection = bulletDir;
}

void Bullet::setPosition(sf::Vector2f& bulletPos)
{
    bulletSprite.setPosition(bulletPos);
}

void Bullet::Update(float deltaTime)
{
    sf::Vector2f normalizedBulletDir = vectorNormalize(bulletDirection);
    bulletSprite.setPosition(bulletSprite.getPosition() + normalizedBulletDir * deltaTime * speed);
    bbox.setPosition(bulletSprite.getPosition());
}

const sf::CircleShape& Bullet::Draw()
{
    return bulletSprite;
}

const sf::FloatRect& Bullet::getGlobalBounds()
{
    return bbox.getGlobalBounds();
}

const sf::Vector2f& Bullet::getPosition()
{
    return bulletSprite.getPosition();
}