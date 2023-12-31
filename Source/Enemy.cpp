#include "Enemy.h"
#include <iostream>


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
    
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f Enemy::getPosition()
{
    return sprite.getPosition();
}

