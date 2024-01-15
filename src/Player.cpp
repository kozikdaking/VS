#include "../include/Player.hpp"
#include "../include/Game.hpp"

Player::Player(Game *game) : Entity(game), playerSpeed(0.5f) {
  m_type = Type::PLAYER;
  sprite.setTexture(*game->GetTexture("player"));
  m_rect = sf::IntRect(0, 0, 30, 31);
  sprite.setTextureRect(m_rect);
  sprite.setPosition(sf::Vector2f(600, 800));
  sprite.setScale(2.0f, 2.0f);
  UpdateRect(120, 124);
  m_Direction = static_cast<int>(Direction::E);
}

void Player::Update() {
  int frameWidth = 30;
  int frameHeight = 33;
  int numFrames = 4;
  int xTexture = 0;
  float animationSpeed = 0.5f;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    xTexture =
        int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
    xTexture = xTexture * frameWidth;
    sprite.setTextureRect(sf::IntRect(xTexture, 0, frameWidth, frameHeight));

    sf::Vector2f position = sprite.getPosition();
    sprite.setPosition(position + sf::Vector2f(0.6, 0.0) * playerSpeed *
                                      m_game->getDeltaTime());
    m_Direction = static_cast<int>(Direction::E);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    xTexture =
        int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
    xTexture = xTexture * frameWidth;
    sprite.setTextureRect(sf::IntRect(xTexture, 33, frameWidth, frameHeight));

    sf::Vector2f position = sprite.getPosition();
    sprite.setPosition(position + sf::Vector2f(-0.6, 0.0) * playerSpeed *
                                      m_game->getDeltaTime());
    m_Direction = static_cast<int>(Direction::W);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    sf::Vector2f position = sprite.getPosition();
    sprite.setPosition(position + sf::Vector2f(0.0, 0.6) * playerSpeed *
                                      m_game->getDeltaTime());
    m_Direction = static_cast<int>(Direction::S);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    sf::Vector2f position = sprite.getPosition();
    sprite.setPosition(position + sf::Vector2f(0.0, -0.6) * playerSpeed *
                                      m_game->getDeltaTime());
    m_Direction = static_cast<int>(Direction::N);
  }
  UpdateRect(120, 124);
  if (m_shootClock.getElapsedTime().asMilliseconds() >= 500.0f) {

    UseWeapons();
    m_shootClock.restart();
  }
}

void Player::Draw() { m_game->DrawSprite(sprite); }

sf::Vector2f Player::getPosition() const { return sprite.getPosition(); }

sf::Vector2f Player::getPlayerPosition() const { return sprite.getPosition(); }

void Player::UseWeapons() {
  std::shared_ptr<Knife> knife = std::make_shared<Knife>(m_game);
  m_game->AddEntity(knife);
  switch (m_Direction) {
  case static_cast<int>(Direction::E):
    knife->setShootingDirection(sf::Vector2f(1.0, 0.0));
    knife->setSpriteRotation(0.0f);
    break;
  case static_cast<int>(Direction::W):
    knife->setShootingDirection(sf::Vector2f(-1.0, 0.0));
    knife->setSpriteRotation(-180.0f);
    break;
  case static_cast<int>(Direction::S):
    knife->setShootingDirection(sf::Vector2f(0.0, 1.0));
    knife->setSpriteRotation(90.0f);
    break;
  case static_cast<int>(Direction::N):
    knife->setShootingDirection(sf::Vector2f(0.0, -1.0));
    knife->setSpriteRotation(-90.0f);
    break;
  }
}