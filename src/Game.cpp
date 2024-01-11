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
    // Load textures
    AddTexture("knife", "images/knife.png");
    AddTexture("player", "images/spritesheet.png");
    AddTexture("enemy", "images/enemy.png");

    mPlayer = new Player(this);
    new Knife(this);
    new Enemy(this);
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

sf::Texture* Game::GetTexture(std::string&& name)
{
    return mTextures[name];
}

void Game::AddTexture(std::string&& name, std::string&& filename)
{
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(filename);
    mTextures.emplace(name, texture);
}