#include "../include/Entity.hpp"
#include "../include/Game.hpp"

Entity::Entity(Game *game) : m_game(game) {
  //   m_game->AddEntity(this->shared_from_this());
}

void Entity::init() { m_game->AddEntity(shared_from_this()); }

Type Entity::getType() const { return m_type; }

sf::IntRect Entity::getRect() const { return m_rect; }

void Entity::UpdateRect(int width, int height) {
  sf::Vector2f pos = m_sprite.getPosition();
  m_rect = sf::IntRect(pos.x, pos.y, pos.x + width, pos.y + height);
}