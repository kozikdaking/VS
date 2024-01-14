#include "../include/Entity.hpp"

Entity::Entity(Game *game)
    : m_game(game)
{
    m_game->AddEntity(std::shared_ptr<Entity>(this));
}

Type Entity::getType() const
{
    return m_type;
}

sf::IntRect Entity::getRect() const
{
    return m_rect;
}

void Entity::UpdateRect(int width, int height)
{
    sf::Vector2f pos = m_sprite.getPosition();
    m_rect = sf::IntRect(pos.x, pos.y, pos.x + width, pos.y + height);
}