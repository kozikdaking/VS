#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Enemy.hpp"
#include "Entity.hpp"
#include "Knife.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Camera.hpp"

class Game {
public:
  Game();
  ~Game();
  bool InitializeGame();
  void RunMainLoop();
  void Shutdown();
  void AddEntity(std::shared_ptr<Entity> entity);
  void RemoveEntity(std::weak_ptr<Entity> entity);
  std::shared_ptr<sf::Texture> GetTexture(const std::string &name);
  float getDeltaTime() const;
  void DrawSprite(sf::Sprite sprite);
  sf::Vector2f GetPlayerPosition() const;
  float getHeight() const;
  float getWidth() const;
  float getElapsedTimeAsSeconds() const;
  bool checkWeaponCollision(std::shared_ptr<Entity> const &entity) const;
  sf::Keyboard::Key getKey() const;
  void setView(sf::View& view);

private:
  void ProcessInput();
  void UpdateGame();
  void GenerateOutput();
  void AddTexture(std::string &&name, std::string &&filename);

  sf::Keyboard::Key mState;
  std::unordered_map<std::string, std::shared_ptr<sf::Texture>> mTextures;
  std::vector<std::shared_ptr<Entity>> mEntities;
  sf::RenderWindow mWindow;
  sf::Clock mClock;
  float mDeltaTime;
  bool mIsRunning;
  std::unique_ptr<Map> mMap;
  std::shared_ptr<Player> mPlayer;
  const float mHeight;
  const float mWidth;
  std::unique_ptr<Camera> mCamera;
};