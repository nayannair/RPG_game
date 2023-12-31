#include "Player.h"
#include <iostream>

void Player::Load()
{
    if (texture.loadFromFile("Assets/Player/Texture/MainGuySpriteSheet.png"))
    {
        std::cout << "Character texture loaded successfully\n";
        sprite.setTexture(texture);

        int spriteIndex_x = 0;
        int spriteIndex_y = 0;

        sprite.setTextureRect(sf::IntRect(spriteIndex_x * 41, spriteIndex_y * 36, 41, 36));
        sprite.setScale(2, 2);
    }

    else
        std::cout << "Character texture loading failed!\n";
}

void Player::Update()
{
    sf::Vector2f position = sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.setPosition(position + sf::Vector2f(1, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.setPosition(position + sf::Vector2f(0, 1));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.setPosition(position + sf::Vector2f(-1, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.setPosition(position + sf::Vector2f(0, -1));
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Vector2f Player::getPosition()
{
    return sprite.getPosition();
}