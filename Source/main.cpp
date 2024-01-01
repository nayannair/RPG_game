#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Enemy.h"
#include "Text.h"
#include "Framerate.h"
#include "BulletManager.h"


int main()
{
    /******************** Render Window *************************/
    
    sf::RenderWindow window(sf::VideoMode(960,540), "RPG Game");
    sf::Event event;
    window.setFramerateLimit(60);

    /******************** Render Window *************************/



    /******************** Load Player Sprite/Texture *************************/

    Player playerChar;
    playerChar.Initialize();
    playerChar.Load();

    /******************** Load Player Sprite/Texture *************************/

    /***************************** Bullet Sprite *****************************/

    BulletManager bulletManager;
    bulletManager.Load();
    /***************************** Bullet Sprite *****************************/

    /***************************** Enemy Sprite *****************************/
    
    Enemy firstEnemy;
    firstEnemy.Initialize();
    firstEnemy.Load();

    /***************************** Enemy Sprite *****************************/

    /******************** Text Components *************************/

    //Text displayText;
    //displayText.Load();

    Framerate frameRateText;
    frameRateText.Load();
    
    /******************** Text Components *************************/

    /***************************** Clock *****************************/

    sf::Clock clock;

    /***************************** Clock *****************************/

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        /**************************** Update ********************************/

        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMicroseconds();

        float framerate = 1000000 / deltaTime;

        // Player
        playerChar.Update(deltaTime,firstEnemy);

        //Bullet

        sf::Vector2f mousePos;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
        }
        bulletManager.Update(playerChar,mousePos,firstEnemy,deltaTime);

        //Enemy
        firstEnemy.Update();

        //Text Components
        //displayText.Update();
        frameRateText.Update(framerate);

        /**************************** Update ********************************/


        /******************** Draw *************************/

        window.clear(sf::Color::Green);

        playerChar.Draw(window);
        bulletManager.Draw(window);
        firstEnemy.Draw(window);

        frameRateText.Draw(window);

        window.display();

        /******************** DRAW *************************/

    }


    return 0;
}