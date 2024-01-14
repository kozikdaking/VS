#include "../include/Knife.hpp"

Knife::Knife(Game *game)
	: Entity(game)
{
	m_type = Type::WEAPON;
	m_speed = 0.7f;
	std::shared_ptr<sf::Texture> texture = m_game->GetTexture("knife");
	m_sprite.setTexture(*texture.get());
	m_sprite.setScale(0.25, 0.25);
	sf::IntRect text_rect = m_sprite.getTextureRect();
	auto vec = m_game->GetPlayerPosition();
	vec.x += 16;
	vec.y += 16;
	m_sprite.setPosition(vec);
	UpdateRect(text_rect.width * 0.25, text_rect.height * 0.25);
}

void Knife::Update()
{
	m_sprite.move(shootingDirection * m_speed * m_game->getDeltaTime());

	sf::Vector2f bulletPosition = m_sprite.getPosition();
	std::shared_ptr<Knife> self;
	if (bulletPosition.x < 0 || bulletPosition.x > m_game->getWidth() ||
		bulletPosition.y < 0 || bulletPosition.y > m_game->getHeight())
	{
		m_game->RemoveEntity(std::weak_ptr<Entity>(self));
	}

	UpdateRect(32, 32);
	if (m_game->checkWeaponCollision(self))
	{
		m_game->RemoveEntity(std::weak_ptr<Entity>(self));
	}
}

void Knife::Draw()
{
	m_game->DrawSprite(m_sprite);
}

void Knife::setShootingDirection(sf::Vector2f dir)
{
	shootingDirection = dir;
}

void Knife::setSpriteRotation(float rot)
{
	m_sprite.setRotation(rot);
}