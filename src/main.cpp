#include "../include/Game.hpp"
#include <iostream>

int main() {
  Game game;
  if (!game.InitializeGame()) {
    std::cout << "Game failed to initialize\n";
    return -1;
  }
  game.RunMainLoop();

  return 0;
}