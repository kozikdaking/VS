#include "Knife.h"

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
	sprite.setOrigin(30, 30);
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


	// rotation of the image

	if (shootClock.getElapsedTime().asMilliseconds() >= shootCooldown)
	{
		if (shootingDirection != sf::Vector2f(0.0f, 0.0f))
		{
			sf::Sprite bullet;
			bullet.setTexture(texture);
			bullet.setScale(0.5,0.5);

			if (shootingDirection.x < 0.0f) {
				bullet.setScale(-0.5f, 0.5f);
			}
			else if (shootingDirection.x > 0.0f) {
				bullet.setScale(0.5f, 0.5f);
			}

			if (shootingDirection.y < 0.0f) {
				bullet.setRotation(-90.0f);
			}
			else if (shootingDirection.y > 0.0f) {
				bullet.setRotation(90.0f);
			}

			bullet.setPosition(playerPosition);
			bullets.push_back(bullet);
			bulletDirections.push_back(shootingDirection);
			shootClock.restart();
		}
	}

}

void Knife::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move(bulletDirections[i] * 3.0f); // Adjust speed as needed
		window.draw(bullets[i]);
	}
}
