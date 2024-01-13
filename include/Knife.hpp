#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"
#include <string>

class Knife : protected Entity
{
public:
	Knife(class Game* game);
	void Update();
	void Draw();
	void SetShootingDirection(sf::Vector2f dir) { shootingDirection = dir; }
	const float shootCooldown = 500.0f; //as ms
	sf::Vector2f shootingDirection;
	void SetSpriteRotation(float rot) {m_sprite.setRotation(rot);}
};