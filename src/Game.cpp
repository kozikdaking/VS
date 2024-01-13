#include "../include/Game.hpp"
#include <algorithm>

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
    // new Knife(this);
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
    mState = event.key.code;
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

void Game::RemoveEntity(Entity* entity)
{
    auto iter = std::find(mEntities.begin(), mEntities.end(), entity);
    if (iter != mEntities.end())
    {
        std::iter_swap(iter, mEntities.end()-1);
        mEntities.pop_back();
    }
}

bool Game::checkWeaponCollision(Entity* entity)
{
    if (entity->getType() != WEAPON)
    {
        std::cout << "Must use weapon\n";
        return false;
    }

    for (auto enemy: mEntities)
    {
        if (enemy->getType() == ENEMY)
        {
            sf::IntRect weapon_r = entity->getRect();
            sf::IntRect enemy_r = enemy->getRect();
            if (weapon_r.left >= enemy_r.left && weapon_r.width <= enemy_r.width &&
                weapon_r.top >= enemy_r.top && weapon_r.height <= enemy_r.height) return true;
        }
    }
    return false;
}