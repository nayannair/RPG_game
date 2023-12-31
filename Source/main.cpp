#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"



int main()
{
    /******************** Render Window *************************/
    
    sf::RenderWindow window(sf::VideoMode(960,540), "RPG Game");
    sf::Event event;

    /******************** Render Window *************************/



    /******************** Load Player Sprite/Texture *************************/

    Player playerChar;
    playerChar.Load();

    /******************** Load Player Sprite/Texture *************************/

    /***************************** Bullet Sprite *****************************/

    Bullet playerbullet;

    /***************************** Bullet Sprite *****************************/

    /***************************** Enemy Sprite *****************************/
    
    Enemy firstEnemy;
    firstEnemy.Load();

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

        /**************************** Update ********************************/

        // Player
        playerChar.Update();

        //Bullet
        playerbullet.Update(playerChar,firstEnemy);

        /**************************** Update ********************************/


        /******************** Draw *************************/

        window.clear(sf::Color::Green);

        playerChar.Draw(window);
        playerbullet.Draw(window);
        firstEnemy.Draw(window);

        window.display();

        /******************** DRAW *************************/

    }

       

    return 0;
}