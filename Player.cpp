#include "player.h"

void Player::Load()
{

    if (texture.loadFromFile("images/sprite.png"))
    {
        std::cout << "Player image has been loaded" << std::endl;

    }
    else
    {
        std::cout << "Player image load has been failed" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 34, 33));
    sprite.setPosition(sf::Vector2f(600, 800));

}

void Player::Initialize()
{
    sprite.setScale(2.0f, 2.0f);
}

void Player::Update(float deltaTime, sf::RenderWindow& window)
{
    int frameWidth = 34;
    int frameHeight = 33;
    int numFrames = 4;
    int xTexture = 0;
    float animationSpeed = 0.9f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        xTexture = int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
        xTexture = xTexture * frameWidth;
        sprite.setTextureRect(sf::IntRect(xTexture, 0, frameWidth, frameHeight));

        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.6, 0.0) * playerSpeed * deltaTime);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        xTexture = int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
        xTexture = xTexture * frameWidth;
        sprite.setTextureRect(sf::IntRect(xTexture, 33, frameWidth, frameHeight));

        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(-0.6, 0.0) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.0, 0.6) * playerSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.0, -0.6) * playerSpeed * deltaTime);
    }
}

void Player::Draw(sf::RenderWindow& window, float deltaTime)
{
    window.draw(sprite);

}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}