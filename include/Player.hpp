#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>

class Player
{
private:
    float playerSpeed = 0.5f;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    void Load();
    void Initialize();
    void Update(float deltaTime, sf::RenderWindow& window);
    void Draw(sf::RenderWindow& window, float deltaTime);
    sf::Vector2f getPosition() const;
    sf::Vector2f getPlayerPosition() const {
        return sprite.getPosition();
    }
};