#include "../include/Game.hpp"

Game::Game()
:mWindow(sf::VideoMode(800, 600), "My window")
,mIsRunning(true)
{ 
}

Game::~Game()
{}

bool Game::Initialize()
{
    // Todo: Loading enemy graphics
    return true;
}

void Game::RunLoop()
{
    while (mIsRunning)
    {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput()
{
    //Process keyboard input
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Shutdown();
    }
}

void Game::UpdateGame()
{
    //Update entities
}

void Game::GenerateOutput()
{
    mWindow.clear();
    // Draw entities to the screen
    mWindow.display();
}

void Game::Shutdown()
{
    mWindow.close();
}