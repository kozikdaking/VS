#pragma once
#include <string>
#include <cfloat>

#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity() = default;
    ~Entity() = default;
    virtual void Update(sf::Clock &clock) = 0;
    virtual void Draw(sf::RenderWindow &window) = 0;
    virtual void DrawAnimation(sf::Clock &clock) = 0;
    bool LoadEntitySheet(const std::string &k_filename);

protected:
    sf::Sprite m_sprite;
    sf::Texture m_sprite_sheet;
    sf::Vector2f m_position;
    float m_speed;
};