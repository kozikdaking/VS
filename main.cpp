#include <SFML/Graphics.hpp>
#include "player.h"


int main()
{
    //-------------------------------INITIALIZE----------------------------
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(240);
    //-------------------------------INITIALIZE----------------------------

    Player player;
    //Enemy enemy;
    sf::Clock clock;

    //-------------------------------INITIALIZE----------------------------

    player.Initialize();
    //enemy.Initialize();
    //-------------------------------INITIALIZE----------------------------

    //--------------------------------LOAD----------------------------
    player.Load();
    //enemy.Load();
    //--------------------------------LOAD----------------------------

    //--------------------------------UPDATE----------------------------
    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        double deltaTimeSeconds = deltaTime.asMilliseconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.Update(deltaTimeSeconds, window);
        //enemy.Update(player, deltaTimeSeconds);

        //--------------------------------UPDATE----------------------------

        //--------------------------------DRAW----------------------------
        window.clear();
        //enemy.Draw(window);
        player.Draw(window, deltaTimeSeconds);
        window.display();
    }
    //--------------------------------DRAW----------------------------

    return 0;
}
