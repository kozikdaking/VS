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
	std::vector<sf::Sprite> bullets;
	std::vector<sf::Vector2f> bulletDirections;
	sf::Clock shootClock;
	const float shootCooldown = 500.0f; //as ms

public:
	void Load();
	void Initialize();
	void Update(float deltaTime, sf::RenderWindow& window, const Player& player);
	void Draw(sf::RenderWindow& window);

};
