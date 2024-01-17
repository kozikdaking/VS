#include "../include/Map.hpp"
#include "../include/Game.hpp"

Map::Map(Game* game)
:m_game(game)
{
    m_tilemap = *game->GetTexture("library_tiles");
}

void Map::Initialize()
{
    AddTile(374, 238, 32, 32, false, "ground_1");
    AddTile(342, 238, 32, 32, false, "ground_2");
    int x_axis = m_game->getWidth() / 48;
    int y_axis = m_game->getHeight() / 48;
    for (int i = 0; i < y_axis; i++)
    {
        m_level.push_back(std::vector<Tile>{});
        for (int j = 0; j < x_axis; j++)
        {
            Tile tile;
            if (j % 2 == 0)
            {
                tile = Tile{m_tiles["ground_1"].m_sprite, m_tiles["ground_1"].is_solid};
            }
            else 
            {
                tile = Tile{m_tiles["ground_2"].m_sprite, m_tiles["ground_2"].is_solid};
            }
            tile.m_sprite.setPosition(j*48, i*48);
            m_level[i].push_back(tile);
        }
    }
}

void Map::AddTile(int x, int y, int width, int length, bool solid, std::string name)
{
    sf::Sprite sprite;
    sprite.setTexture(m_tilemap);
    sprite.setTextureRect(sf::IntRect(x, y, width, length));
    sprite.setScale(1.5f, 1.5f);
    Tile tile{sprite, solid};
    m_tiles.emplace(name, tile);
}

void Map::Draw()
{
    for (auto vec : m_level)
    {
        for (auto tile: vec)
        {
            m_game->DrawSprite(tile.m_sprite);
        }
    }
}