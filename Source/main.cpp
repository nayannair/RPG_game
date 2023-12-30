#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

/* Normalize a vector */
sf::Vector2f vectorNormalize(sf::Vector2f& vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;
    return normalizedVector;
}



int main()
{
    /******************** Render Window *************************/
    
    sf::RenderWindow window(sf::VideoMode(960,540), "RPG Game");
    sf::Event event;

    /******************** Render Window *************************/



    /******************** Load Player Sprite/Texture *************************/

    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Texture/MainGuySpriteSheet.png"))
    {
        std::cout << "Character texture loaded successfully\n";
        playerSprite.setTexture(playerTexture);

        int spriteIndex_x = 0;
        int spriteIndex_y = 0;

        playerSprite.setTextureRect(sf::IntRect(spriteIndex_x * 41, spriteIndex_y * 36, 41, 36));
        playerSprite.setScale(2, 2);
    }
        
    else
        std::cout << "Character texture loading failed!\n";

    /******************** Load Player Sprite/Texture *************************/

    /***************************** Bullet Sprite *****************************/

    std::vector<sf::CircleShape> bulletAmmo;
    bulletAmmo.reserve(10);

    /***************************** Bullet Sprite *****************************/

    /***************************** Enemy Sprite *****************************/
    
    sf::Vector2f enemyPosition(500.0f, 0.0f);

    /***************************** Enemy Sprite *****************************/



    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Vector2f position = playerSprite.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::CircleShape newBullet(5.0f);
            newBullet.setPosition(playerSprite.getPosition() + sf::Vector2f(41.0 / 2, 36.0 / 2));
            newBullet.setFillColor(sf::Color::Red);
            newBullet.setOutlineThickness(2.0f);
            bulletAmmo.push_back(newBullet);
        
        }

        for (int i = 0; i < bulletAmmo.size(); i++)
        {
            sf::Vector2f bulletDirection = enemyPosition - playerSprite.getPosition();
            sf::Vector2f normalizedBulletDir = vectorNormalize(bulletDirection);
            bulletAmmo[i].setPosition(bulletAmmo[i].getPosition() + normalizedBulletDir);
        }

        /******************** DRAW *************************/

        window.clear(sf::Color::Green);

        window.draw(playerSprite);

        for (int i = 0; i < bulletAmmo.size(); i++)
        {
            window.draw(bulletAmmo[i]);
        }

        window.display();

        /******************** DRAW *************************/

    }

       

    return 0;
}