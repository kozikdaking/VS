#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Knife.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"

class Game
{
public:
    Game();
    ~Game();
    bool InitializeGame();
    void RunMainLoop();
    void Shutdown();
    void AddEntity(std::shared_ptr<class Entity> entity);
    void RemoveEntity(std::weak_ptr<class Entity> entity);
    std::shared_ptr<sf::Texture> GetTexture(const std::string &name);
    float getDeltaTime() const;
    void DrawSprite(sf::Sprite sprite);
    sf::Vector2f GetPlayerPosition() const;
    float getHeight() const;
    float getWidth() const;
    float getElapsedTimeAsSeconds() const;
    bool checkWeaponCollision(std::shared_ptr<Entity> const &entity) const;
    sf::Keyboard::Key getKey() const;

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void AddTexture(std::string &&name, std::string &&filename);

    sf::Keyboard::Key mState;
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> mTextures;
    std::vector<std::shared_ptr<Entity>> mEntities;
    sf::RenderWindow mWindow;
    sf::Clock mClock;
    float mDeltaTime;
    bool mIsRunning;
    std::shared_ptr<class Player> mPlayer;
    std::shared_ptr<class Knife> mKnife;
    const float mHeight;
    const float mWidth;
};