#include "../include/Entity.hpp"
#include "../include/Game.hpp"

Entity::Entity(Game* game)
:m_game(game)
{
    m_game->AddEntity(this);
}