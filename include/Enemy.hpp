#pragma once

#include <memory>
#include <random>

#include "Entity.hpp"

class Player
{
public:
    Player() = default;
};

class Enemy : public Entity
{
public:
    Enemy(float x, float y, float speed, sf::IntRect enemy_rect);
    ~Enemy() = default;
    void Update(sf::Clock &clock) override;
    void Draw(sf::RenderWindow &window) override;
    void DrawAnimation(sf::Clock &clock) override;
    void FollowPlayer(const Player &k_player);

private:
    std::unique_ptr<Player> m_ptr_player;
    sf::IntRect m_enemy_rect;
};