#include <stdio.h>
#include "../include/Enemy.hpp"
#include "../include/FileManagement.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(240);

    Enemy enemy(0, 0, 0.1f, sf::IntRect(0, 0, 32, 32));
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        enemy.Draw(window);
        enemy.Update(clock);
        window.display();
    }

    return 0;
}