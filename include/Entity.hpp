#pragma once
#include <string>
#include <cfloat>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Game.hpp"

enum class Type
{
    ENEMY,
    PLAYER,
    WEAPON
};

enum class Direction
{
    W,
    S,
    N,
    E
};

class Entity
{
public:
    Entity(class Game *game);
    ~Entity() = default;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    Type getType() const;
    sf::IntRect getRect() const;
    void UpdateRect(int width, int height);

protected:
    sf::Sprite m_sprite;
    sf::Texture m_sprite_sheet;
    sf::Vector2f m_position;
    float m_speed;
    class Game *m_game;
    Type m_type;
    sf::IntRect m_rect;
};