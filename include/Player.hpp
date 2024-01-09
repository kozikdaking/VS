#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Entity.hpp"

class Player : public Entity
{
private:
    float playerSpeed = 0.5f;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Player(class Game* game);
    void Draw() override;
    void Update() override;
    sf::Vector2f getPosition() const;
    sf::Vector2f getPlayerPosition() const {
        return sprite.getPosition();
    }
};