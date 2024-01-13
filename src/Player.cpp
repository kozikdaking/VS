#include "../include/Game.hpp"
#include "../include/Player.hpp"


Player::Player(Game* game)
:Entity(game)
{
    m_type = PLAYER;
    sprite.setTexture(*game->GetTexture("player"));
    m_rect = sf::IntRect(0, 0, 30, 31);
    sprite.setTextureRect(m_rect);
    sprite.setPosition(sf::Vector2f(600, 800));
    sprite.setScale(2.0f, 2.0f);
    UpdateRect(120, 124);
    m_Direction = E;
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
        m_Direction = E;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        xTexture = int(sprite.getPosition().x / frameWidth * animationSpeed) % numFrames;
        xTexture = xTexture * frameWidth;
        sprite.setTextureRect(sf::IntRect(xTexture, 33, frameWidth, frameHeight));

        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(-0.6, 0.0) * playerSpeed * m_game->getDeltaTime());
        m_Direction = W;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.0, 0.6) * playerSpeed * m_game->getDeltaTime());
        m_Direction = S;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sf::Vector2f position = sprite.getPosition();
        sprite.setPosition(position + sf::Vector2f(0.0, -0.6) * playerSpeed * m_game->getDeltaTime());
        m_Direction = N;
    }
    UpdateRect(120, 124);
    if (m_shootClock.getElapsedTime().asMilliseconds() >= 500.0f)
    {
        UseWeapons();
        m_shootClock.restart();
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

void Player::UseWeapons()
{
    Knife* knife = new Knife(m_game);

    switch (m_Direction)
    {
        case E:
            knife->SetShootingDirection(sf::Vector2f(1.0, 0.0));
            knife->SetSpriteRotation(0.0f);
            break;
        case W:
            knife->SetShootingDirection(sf::Vector2f(-1.0, 0.0));
            knife->SetSpriteRotation(-180.0f);
            break;
        case S:
            knife->SetShootingDirection(sf::Vector2f(0.0, 1.0));
            knife->SetSpriteRotation(90.0f);
            break;
        case N:
            knife->SetShootingDirection(sf::Vector2f(0.0, -1.0));
            knife->SetSpriteRotation(-90.0f);
            break;
    }
}