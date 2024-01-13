#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Entity.hpp"
#include "Knife.hpp"

class Player : public Entity
{
private:
    float playerSpeed = 0.5f;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Clock m_shootClock;
    Direction m_Direction;

public:
    Player(class Game* game);
    void Draw() override;
    void Update() override;
    sf::Vector2f getPosition() const;
    sf::Vector2f getPlayerPosition() const {
        return sprite.getPosition();
    }
    void UseWeapons();
};