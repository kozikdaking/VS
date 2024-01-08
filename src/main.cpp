#include <iostream>
#include "../include/Game.hpp"

int main()
{
    Game game;
    if (!game.Initialize())
    {
        std::cout << "Game failed to initialize\n";
        return -1;
    }
    game.RunLoop();
   
    return 0;
}