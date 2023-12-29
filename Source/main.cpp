#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "First Window");
    sf::Event event;
    sf::CircleShape circle;
    circle.setRadius(5.0f);
    circle.setPosition(sf::Vector2f(10.0f, 10.0f));
    circle.setFillColor(sf::Color::Red);


    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        window.clear(sf::Color::Green);

        window.draw(circle);

        window.display();
    }

       

    return 0;
}