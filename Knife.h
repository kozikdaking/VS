#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Knife
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f shootingDirection;  // Direction in which the player is shooting
	std::vector<sf::Sprite> bullets;  // Using Sprite instead of CircleShape
	std::vector<sf::Vector2f> bulletDirections;
	sf::Clock shootClock;  // Clock for shooting cooldown
	const float shootCooldown = 500.0f;  // Cooldown in milliseconds
	const float distanceFromPlayer = 20.0f;

public:
	void Load();
	void Initialize();
	void Update(float deltaTime, sf::RenderWindow& window, const Player& player);
	void Draw(sf::RenderWindow& window);

};
