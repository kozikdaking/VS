#include "../include/Game.hpp"

Game::Game()
:mHeight(1080)
,mWidth(1920)
,mWindow(sf::VideoMode(1920, 1080), "My window")
,mIsRunning(true)
,mPlayer(nullptr)
,mKnife(nullptr)
{ 
    mWindow.setFramerateLimit(60);
}

Game::~Game()
{}

bool Game::Initialize()
{
    mPlayer = new Player(this);
    mKnife = new Knife(this);
    mKnife->Load();
    mPlayer->Load();
    mPlayer->Initialize();
    mKnife->Initialize();
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
    mPlayer->Update();
    mKnife->Update();
}

void Game::GenerateOutput()
{
    mWindow.clear();
    mPlayer->Draw();
    mKnife->Draw();
    mWindow.display();
}

void Game::Shutdown()
{
    mWindow.close();
}