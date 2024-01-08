#include "../include/Entity.hpp"

bool Entity::LoadEntitySheet(const std::string &k_filename)
{
    if (!m_sprite_sheet.loadFromFile(k_filename))
    {
        return false;
    }
    return true;
}