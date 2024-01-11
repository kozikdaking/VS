#pragma once

#include <random>

#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(Game* game);
    ~Enemy() = default;
    void Update() override;
    void Draw() override;
    void DrawAnimation();

private:
    sf::IntRect m_enemy_rect;
};