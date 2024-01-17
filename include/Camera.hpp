#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera(class Game* game);
    void follow(const sf::Vector2f &position);
    const sf::View& getView() const;

private:
    sf::View mView;
    class Game* mGame;
    sf::Vector2f mPosition;
};