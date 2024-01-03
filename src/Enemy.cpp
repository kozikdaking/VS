#include "../include/Enemy.hpp"

Enemy::Enemy(float x, float y, float speed, sf::IntRect enemy_rect)
{
    m_position.x = x;
    m_position.y = y;
    m_speed = speed;
    m_enemy_rect = enemy_rect;
    m_sprite.setTexture(m_sprite_sheet);
    m_sprite.setTextureRect(m_enemy_rect);
}

void Enemy::Update(sf::Clock &clock)
{
    m_position.x += m_speed;
    m_sprite.setPosition(m_position);
    DrawAnimation(clock);
}

void Enemy::Draw(sf::RenderWindow &window)
{
    window.draw(m_sprite);
}

void Enemy::DrawAnimation(sf::Clock &clock)
{
    float animation_speed = 0.5f;
    if (clock.getElapsedTime().asSeconds() > 0.5f)
    {
        if (m_enemy_rect.left == 96)
        {
            m_enemy_rect.left = 0;
        }
        else
        {
            m_enemy_rect.left += 32;
        }
        m_sprite.setTextureRect(m_enemy_rect);
        clock.restart();
    }
}
