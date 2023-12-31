#include "Enemy.h"
#include <iostream>


void Enemy::Initialize()
{
    bbox.setOutlineThickness(2.0f);
    bbox.setOutlineColor(sf::Color::Red);
    bbox.setFillColor(sf::Color::Transparent);
    bbox.setSize(sf::Vector2f(41, 36));
    bbox.setScale(2, 2);
}

void Enemy::Load()
{
    if (texture.loadFromFile("Assets/Enemy/Texture/MainGuySpriteSheet.png"))
    {
        std::cout << "Enemy texture loaded successfully\n";
        sprite.setTexture(texture);

        int spriteIndex_x = 2;
        int spriteIndex_y = 2;

        sprite.setTextureRect(sf::IntRect(spriteIndex_x * 41, spriteIndex_y * 36, 41, 36));
        sprite.setScale(2, 2);
        sprite.setPosition(sf::Vector2f(200.0f, 200.0f));
    }

    else
        std::cout << "Enemy texture loading failed!\n";
}

void Enemy::Update()
{
    bbox.setPosition(sprite.getPosition());
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(bbox);
}

sf::Vector2f Enemy::getPosition()
{
    return sprite.getPosition();
}

