#include "../include/Knife.hpp"

void Knife::Load()
{
	if (texture.loadFromFile("images/knife.png"))
	{
		std::cout << "Knife image has been loaded" << std::endl;
	}
	else
	{
		std::cout << "Knife image load has been failed" << std::endl;
	}
}

void Knife::Initialize()
{
	sprite.setTexture(texture);
	sprite.setScale(0.5, 0.5);

	bullet.setTexture(texture);
	bullet.setScale(0.5, 0.5);
}

void Knife::Update(float deltaTime, sf::RenderWindow& window, const Player& player)
{
	sf::Vector2f playerPosition = player.getPosition();

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
		bullets[i].move(bulletDirections[i] * speed * deltaTime);

		sf::Vector2f bulletPosition = bullets[i].getPosition();
		if (bulletPosition.x < 0 || bulletPosition.x > window.getSize().x ||
			bulletPosition.y < 0 || bulletPosition.y > window.getSize().y)
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

void Knife::Draw(sf::RenderWindow& window, float deltaTime)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(bulletDirections[i] * speed * deltaTime);
		window.draw(bullets[i]);
	}
}