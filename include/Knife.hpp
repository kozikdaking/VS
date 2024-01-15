#pragma once
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Player.hpp"

class Knife : public Entity {
public:
  Knife(class Game *game);
  void Update();
  void Draw();
  void setShootingDirection(sf::Vector2f dir);
  void setSpriteRotation(float rot);

private:
  const float shootCooldown = 500.0f; // as ms
  sf::Vector2f shootingDirection;
};