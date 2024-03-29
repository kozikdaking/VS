#include "../include/Enemy.hpp"
#include "../include/Game.hpp"

Enemy::Enemy(Game *game) : Entity(game) {
  m_type = Type::ENEMY;
  m_position.x = 50;
  m_position.y = 50;
  m_speed = 0.01f;
  m_rect = sf::IntRect(0, 0, 30, 31);
  m_sprite.setTexture(*m_game->GetTexture("enemy"));
  m_sprite.setTextureRect(m_rect);
  m_sprite.setScale(2.0f, 2.0f);
  UpdateRect(120, 124);
}

void Enemy::Update() {
  sf::Vector2f p_pos = m_game->GetPlayerPosition();
  m_position.x += (p_pos.x - m_position.x) * m_speed;
  m_position.y += (p_pos.y - m_position.y) * m_speed;
  m_sprite.setPosition(m_position);
  UpdateRect(120, 124);
  DrawAnimation();
}

void Enemy::Draw() { m_game->DrawSprite(m_sprite); }

void Enemy::DrawAnimation() {
  const float animation_speed = 0.1f;
  const int texture_width = 140;

  if (m_game->getElapsedTimeAsSeconds() > animation_speed) {
    if (m_rect.left + m_rect.width >= texture_width) {
      m_rect.left = 0;
    } else {
      m_rect.left += 28;
    }

    m_sprite.setTextureRect(m_rect);
  }
}
