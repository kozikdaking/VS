#include "../include/Camera.hpp"
#include "../include/Game.hpp"

Camera::Camera(Game* game)
:mGame(game),
mView(sf::Vector2f(0, 0), sf::Vector2f(game->getWidth(), game->getHeight()))
{
    mPosition = mGame->GetPlayerPosition();
    mView.setCenter(mPosition);
    mGame->setView(mView);
}

void Camera::follow(const sf::Vector2f& position)
{
    mView.setCenter(position);
    mGame->setView(mView);
}

const sf::View &Camera::getView() const { return mView; }