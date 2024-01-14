#pragma once

#include <math.h>

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Knife.hpp"
#include "Game.hpp"

class Player : public Entity
{
public:
    Player(class Game *game);
    void Draw();
    void Update();
    sf::Vector2f getPosition() const;
    sf::Vector2f getPlayerPosition() const;
    void UseWeapons();

private:
    float playerSpeed;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock m_shootClock;
    int m_Direction;
};