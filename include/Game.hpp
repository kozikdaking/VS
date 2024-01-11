#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Knife.hpp"
#include "Enemy.hpp"

class Game
{
public:
    Game();
    ~Game();

    bool Initialize();
    void RunLoop();
    void Shutdown();

    void AddEntity(class Entity* entity);
    void RemoveEntity(class Entity* entity);

    sf::Texture* GetTexture(std::string&& name);
    float getDeltaTime() const { return mDeltaTime; }
    void DrawSprite(sf::Sprite sprite) { mWindow.draw(sprite); }
    sf::Vector2f GetPlayerPosition() const { return mPlayer->getPosition(); }
    float getHeight() const { return mHeight; }
    float getWidth() const { return mWidth; }
    float getElapsedTimeAsSeconds() const { return mClock.getElapsedTime().asSeconds(); }

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    void AddTexture(std::string&& name, std::string&& filename);

    std::unordered_map<std::string, sf::Texture*> mTextures;
    std::vector<class Entity*> mEntities;
    sf::RenderWindow mWindow;
    sf::Clock mClock;
    float mDeltaTime;

    bool mIsRunning;

    Player* mPlayer;
    Knife* mKnife;

    const float mHeight;
    const float mWidth;
};