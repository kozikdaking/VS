#pragma once
#include <iostream>
#include "Entity.hpp"

class FileManagement : public Entity
{
public:
    FileManagement() = default;
    ~FileManagement() = default;
    void Update(sf::Clock &clock) override;
    void Draw(sf::RenderWindow &window) override;
    void DrawAnimation(sf::Clock &clock) override;
};