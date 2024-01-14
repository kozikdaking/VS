#include <iostream>
#include "../include/Game.hpp"

int main()
{
    Game game;
    if (!game.InitializeGame())
    {
        std::cout << "Game failed to initialize\n";
        return -1;
    }
    game.RunMainLoop();

    return 0;
}