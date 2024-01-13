#pragma once
#include <string>
#include <cfloat>

#include <SFML/Graphics.hpp>

enum Type {
    ENEMY, PLAYER, WEAPON
};

enum Direction {
    W, S, N, E
};

class Entity
{
public:
    Entity(class Game* game);
    ~Entity() = default;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    Type getType() const { return m_type; }
    sf::IntRect getRect() const { return m_rect; }
    void UpdateRect(int width, int height) {
        sf::Vector2f pos = m_sprite.getPosition();
        m_rect = sf::IntRect(pos.x, pos.y, pos.x + width, pos.y + height);
    }

protected:
    sf::Sprite m_sprite;
    sf::Texture m_sprite_sheet;
    sf::Vector2f m_position;
    float m_speed;
    class Game* m_game;
    Type m_type;
    sf::IntRect m_rect;
};