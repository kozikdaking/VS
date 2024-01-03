#pragma once
#include "Knife.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Knife
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity;
public:
	void Load();
	void Initialize();
	void Update(float deltaTime, sf::RenderWindow& window,const Player& player);
	void Draw(sf::RenderWindow& window);

};

