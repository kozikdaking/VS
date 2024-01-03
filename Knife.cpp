#include "Knife.h"

void Knife::Load()
{
	if (texture.loadFromFile("images/knife.png"))
	{
		std::cout << "knife image has been loaded" << std::endl;	
	}
	else
	{
		std::cout << "knife image load has been failed" << std::endl;
	}
}


void Knife::Initialize()
{
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(500, 600));
	sprite.setScale(0.5, 0.5);
}

void Knife::Update(float deltaTime, sf::RenderWindow& window, const Player& player)
{
	sf::Vector2f playerPosition = player.getPosition();
	//sprite.setPosition(playerPosition);
	//velocity = sf::Vector2f(100.0f, 0.0f);
	//sprite.move(velocity * deltaTime);
}

void Knife::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
