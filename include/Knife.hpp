#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

class Knife : public Entity
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Sprite bullet;
	sf::Vector2f shootingDirection;
	std::vector<sf::Sprite> bullets;
	std::vector<sf::Vector2f> bulletDirections;
	sf::Clock shootClock;
	float speed = 0.7f;
	const float shootCooldown = 500.0f; //as ms

public:
	Knife(class Game* game);
	void Load();
	void Initialize();
	void Update();
	void Draw();
};