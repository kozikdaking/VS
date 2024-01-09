#include "../include/Knife.hpp"
#include "../include/Player.hpp"
#include "../include/Game.hpp"

Knife::Knife(Game* game)
:Entity(game)
{
	sf::Texture* texture = m_game->GetTexture("knife");
	sprite.setTexture(*texture);
	sprite.setScale(0.5, 0.5);

	bullet.setTexture(*texture);
	bullet.setScale(0.5, 0.5);
}

void Knife::Update()
{
	sf::Vector2f playerPosition = m_game->GetPlayerPosition();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		shootingDirection = sf::Vector2f(1.0, 0.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shootingDirection = sf::Vector2f(-1.0, 0.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		shootingDirection = sf::Vector2f(0.0, 1.0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		shootingDirection = sf::Vector2f(0.0, -1.0);
	}

	if (shootClock.getElapsedTime().asMilliseconds() >= shootCooldown)
	{
		if (shootingDirection != sf::Vector2f(0.0f, 0.0f))
		{
			bullet.setRotation(0.0f);
			bullet.setScale(0.5f, 0.5f);

			if (shootingDirection.x < 0.0f)
			{
				bullet.setScale(-0.5f, 0.5f); //left
			}
			else if (shootingDirection.x > 0.0f)
			{
				bullet.setRotation(0.0f); //right
			}
			if (shootingDirection.y < 0.0f)
			{
				bullet.setRotation(-90.0f); //bottom
			}
			else if (shootingDirection.y > 0.0f)
			{
				bullet.setRotation(90.0f); //top
			}

			bullet.setPosition(playerPosition);
			bullets.push_back(bullet);
			bulletDirections.push_back(shootingDirection);
			shootClock.restart();
		}
	}

	for (int i = 0; i < bullets.size(); )
	{
		bullets[i].move(bulletDirections[i] * speed * m_game->getDeltaTime());

		sf::Vector2f bulletPosition = bullets[i].getPosition();
		if (bulletPosition.x < 0 || bulletPosition.x > m_game->getWidth() ||
			bulletPosition.y < 0 || bulletPosition.y > m_game->getHeight())
		{
			//std::cout << "bullet has been removed" << std::endl;
			bullets.erase(bullets.begin() + i);
			bulletDirections.erase(bulletDirections.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

void Knife::Draw()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(bulletDirections[i] * speed * m_game->getDeltaTime());
		m_game->DrawSprite(bullets[i]);
	}
}