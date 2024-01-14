#pragma once

#include <random>

#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(class Game *game);
    ~Enemy() = default;
    void Update();
    void Draw();
    void DrawAnimation();
};