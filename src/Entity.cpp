#include "../include/Entity.hpp"
#include "../include/Game.hpp"

Entity::Entity(Game* game)
:m_game(game)
{
    m_game->AddEntity(this);
}

bool Entity::LoadEntitySheet(const std::string &k_filename)
{
    if (!m_sprite_sheet.loadFromFile(k_filename))
    {
        return false;
    }
    return true;
}