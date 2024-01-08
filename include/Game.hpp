#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class Game
{
public:
    Game();
    ~Game();

    bool Initialize();
    void RunLoop();
    void Shutdown();

    void AddEntity(class Entity* entity);
    void RemoveEntity(class Entity* entity);

    sf::Texture* GetTexture(std::string& name);

private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    std::unordered_map<std::string, std::vector<sf::Texture*>> mTextures;
    std::vector<class Entity*> mEntities;
    sf::RenderWindow mWindow;

    bool mIsRunning;

};