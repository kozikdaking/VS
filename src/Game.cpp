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
    std::cout << mEntities.size();
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
    for (auto entity: mEntities)
    {
        entity->Update();
    }
}

void Game::GenerateOutput()
{
    mWindow.clear();
    for (Entity* entity : mEntities)
    {
        entity->Draw();   
    }
    mWindow.display();
}

void Game::Shutdown()
{
    mWindow.close();
}

void Game::AddEntity(Entity* entity)
{
    mEntities.push_back(entity);
}