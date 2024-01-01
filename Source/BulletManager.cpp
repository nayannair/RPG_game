#include "BulletManager.h"

void BulletManager::Load()
{
    fireRate = 100000; //milliseconds
    fireTimer = 0;
}

void BulletManager::Update(Player& playerChar, sf::Vector2f& mousePos,Enemy& enemy, float deltaTime)
{
    fireTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && fireTimer > fireRate)
    {
        Bullet newBullet;
        sf::Vector2f newBulletDir = mousePos - playerChar.getPosition();
        newBullet.setDirection(newBulletDir);
        sf::Vector2f newBulletPos = playerChar.getPosition() + sf::Vector2f(41.0 / 2, 36.0 / 2);
        newBullet.setPosition(newBulletPos);

        ammo.push_back(newBullet);

        fireTimer = 0;
    }

    for (int i = 0; i < ammo.size(); i++)
    {
        ammo[i].Update(deltaTime);
       
    }

    //Check Collision for bullets
    this->checkCollision(enemy);
    this->checkBounds();
}

void BulletManager::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < ammo.size(); i++)
    {
        window.draw(ammo[i].Draw());
    }
}

void BulletManager::checkCollision(Enemy& enemyObj)
{
    sf::FloatRect enemyBound = enemyObj.bbox.getGlobalBounds();

    for (int i = 0; i < ammo.size(); i++)
    {
        sf::FloatRect bulletBound = ammo[i].getGlobalBounds();

        if (enemyBound.intersects(bulletBound))
        {
            std::cout << "Bullet collided with enemy!!\n";

            //Delete bullet from ammo
            std::swap(ammo[i], ammo[ammo.size() - 1]);
            ammo.pop_back();
            i--;
        }
        else
        {
            //std::cout << "Bullet shooting through empty space...\n";
        }
    }

}

void BulletManager::checkBounds()
{
    float WINDOW_WIDTH_MAX = 960;
    float WINDOW_HEIGHT_MAX = 540;
    float WINDOW_HEIGHT_MIN = 0;
    float WINDOW_WIDTH_MIN = 0;



    for (int i = 0; i < ammo.size(); i++)
    {
        sf::Vector2f bulletPos = ammo[i].getPosition();
        if (bulletPos.x > WINDOW_WIDTH_MAX || bulletPos.y > WINDOW_HEIGHT_MAX || bulletPos.x < WINDOW_WIDTH_MIN || bulletPos.y < WINDOW_HEIGHT_MIN)
        {
            std::cout << "Bullet destroyed! Out of bounds!\n";

            //Delete bullet from ammo
            std::swap(ammo[i], ammo[ammo.size() - 1]);
            ammo.pop_back();
            i--;
        }
    }
}
