#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Knife.h"

int main()
{
    //-------------------------------INITIALIZE----------------------------
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "GAME");
    window.setFramerateLimit(240);
    //-------------------------------INITIALIZE----------------------------
   
    Player player;
    Knife knife;
    sf::Clock clock;
    //-----------------------------------LOAD----------------------------
    knife.Load();
    player.Load();
    //-----------------------------------LOAD----------------------------

    //--------------------------------INITIALIZE----------------------------
    player.Initialize();
    knife.Initialize();
    //--------------------------------INITIALIZE----------------------------

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
        knife.Update(deltaTimeSeconds, window, player);
        //--------------------------------UPDATE----------------------------

        //--------------------------------DRAW----------------------------
        window.clear();
        player.Draw(window, deltaTimeSeconds);
        knife.Draw(window);
        window.display();
    }
    //--------------------------------DRAW----------------------------

    return 0;
}
// move code to the knife.cpp
// add static int to the width/height
// remove bullets when they across the border of the screen
// create some pointers
// try to find better logic
// change cooldown of the bullet(?)
// commit as "added knife dir"
// upload on git