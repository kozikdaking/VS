#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>

struct Tile 
{
    sf::Sprite m_sprite;
    bool is_solid;
};

class Map 
{
public:
    Map(class Game* game);
    void Initialize();
    void Draw();
private:
    void AddTile(int x, int y, int width, int length, bool solid, std::string name);
    class Game* m_game;
    std::vector<std::vector<Tile>> m_level;
    std::unordered_map<std::string, Tile> m_tiles;
    sf::Texture m_tilemap;
};