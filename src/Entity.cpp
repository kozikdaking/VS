#include "../include/Entity.hpp"
#include "../include/Game.hpp"

Entity::Entity(Game* game)
:m_game(game)
{

}

bool Entity::LoadEntitySheet(const std::string &k_filename)
{
    if (!m_sprite_sheet.loadFromFile(k_filename))
    {
        return false;
    }
    return true;
}

void Entity::Update()
{}

void Entity::Draw()
{}

void Entity::DrawAnimation()
{}