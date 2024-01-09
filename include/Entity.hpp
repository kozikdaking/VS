#pragma once
#include <string>
#include <cfloat>

#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(class Game* game);
    ~Entity() = default;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    bool LoadEntitySheet(const std::string &k_filename);

protected:
    sf::Sprite m_sprite;
    sf::Texture m_sprite_sheet;
    sf::Vector2f m_position;
    float m_speed;
    class Game* m_game;
};