#include "../include/Game.hpp"

Game::Game()
:mWindow(sf::VideoMode(1920, 1080), "My window")
,mIsRunning(true)
{ 
    mWindow.setFramerateLimit(60);
}

Game::~Game()
{}

bool Game::Initialize()
{
    mKnife.Load();
    mPlayer.Load();
    mPlayer.Initialize();
    mKnife.Initialize();
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
    sf::Time deltaTime = mClock.restart();
    mDeltaTime = deltaTime.asMilliseconds();
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Shutdown();
    }
}

void Game::UpdateGame()
{
    mPlayer.Update(mDeltaTime, mWindow);
    mKnife.Update(mDeltaTime, mWindow, mPlayer);
}

void Game::GenerateOutput()
{
    mWindow.clear();
    mPlayer.Draw(mWindow, mDeltaTime);
    mKnife.Draw(mWindow, mDeltaTime);
    mWindow.display();
}

void Game::Shutdown()
{
    mWindow.close();
}