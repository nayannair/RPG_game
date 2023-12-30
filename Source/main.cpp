#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "First Window");
    sf::Event event;
    
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("Assets/Player/Texture/MainGuySpriteSheet.png"))
    {
        std::cout << "Character texture loaded successfully\n";
        playerSprite.setTexture(playerTexture);
    }
        
    else
        std::cout << "Character texture loading failed!\n";

    playerSprite.setTextureRect(sf::IntRect(0,0,41,36));
    playerSprite.setScale(2,2);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            sf::Vector2f position = playerSprite.getPosition();
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        }

        window.clear(sf::Color::Green);

        window.draw(playerSprite);

        window.display();
    }

       

    return 0;
}