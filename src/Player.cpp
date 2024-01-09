#include "../include/Game.hpp"
#include "../include/Player.hpp"

Player::Player(Game* game)
:Entity(game)
{
    sprite.setTexture(*game->GetTexture("player"));
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 31));
    sprite.setPosition(sf::Vector2f(600, 800));
    sprite.setScale(2.0f, 2.0f);
}

void Player::Update()
{
    int frameWidth = 30;
    int frameHeight = 33;
    int numFrames = 4;
    int xTexture = 0;
    float animationSpeed = 0.5f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        xTexture = int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
        xTexture = xTexture * frameWidth;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, frameWidth, frameHeight));

        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.6, 0.0) * playerSpeed * m_game->getDeltaTime());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        xTexture = int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
        xTexture = xTexture * frameWidth;
        sprite.setTextureRect(sf::IntRect(xTexture, 33, frameWidth, frameHeight));

        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(-0.6, 0.0) * playerSpeed * m_game->getDeltaTime());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.0, 0.6) * playerSpeed * m_game->getDeltaTime());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.0, -0.6) * playerSpeed * m_game->getDeltaTime());
    }
}

void Player::Draw()
{
    m_game->DrawSprite(sprite);
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}