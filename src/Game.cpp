#include "../include/Game.hpp"
Game::Game()
    : mHeight(1080), mWidth(1920),
      mWindow(sf::VideoMode(1920, 1080), "My window"), mIsRunning(true),
      mPlayer(nullptr), mEnemy(nullptr) {
  mWindow.setFramerateLimit(60);
}

Game::~Game() { Shutdown(); }

bool Game::InitializeGame() {

#ifdef WIN32
  AddTexture("knife", "images/knife.png");
  AddTexture("player", "images/spritesheet.png");
  AddTexture("enemy", "images/enemy.png");

#else
  AddTexture("knife", "../images/knife.png");
  AddTexture("player", "../images/spritesheet.png");
  AddTexture("enemy", "../images/enemy.png");
#endif

  mPlayer = std::make_shared<Player>(this);
  AddEntity(mPlayer);
  mEnemy = std::make_shared<Enemy>(this);
  AddEntity(mEnemy);
  return true;
}

void Game::RunMainLoop() {
  while (mIsRunning) {
    ProcessInput();
    UpdateGame();
    GenerateOutput();
  }
}

void Game::Shutdown() { mWindow.close(); }

void Game::AddEntity(std::shared_ptr<Entity> entity) {
  mEntities.emplace_back(entity);
}

void Game::RemoveEntity(std::weak_ptr<Entity> entity) {
  auto entity_ptr = entity.lock();
  if (entity_ptr) {
    auto iter = std::find(mEntities.begin(), mEntities.end(), entity_ptr);
    if (iter != mEntities.end()) {
      mEntities.erase(iter);
    }
  }
}

std::shared_ptr<sf::Texture> Game::GetTexture(const std::string &name) {
  auto it = mTextures.find(name);
  if (it != mTextures.end()) {
    return it->second;
  } else {
    return nullptr;
  }
}

float Game::getDeltaTime() const { return mDeltaTime; }

void Game::DrawSprite(sf::Sprite sprite) { mWindow.draw(sprite); }

sf::Vector2f Game::GetPlayerPosition() const { return mPlayer->getPosition(); }

float Game::getHeight() const { return mHeight; }

float Game::getWidth() const { return mWidth; }

float Game::getElapsedTimeAsSeconds() const {
  return mClock.getElapsedTime().asSeconds();
}

bool Game::checkWeaponCollision(std::shared_ptr<Entity> const &entity) const {
  if (entity->getType() != Type::WEAPON) {
    std::cout << "Must use weapon\n";
    return false;
  }

  for (std::shared_ptr<Entity> const &enemy : mEntities) {
    if (enemy->getType() == Type::ENEMY) {
      sf::IntRect weapon_r = entity->getRect();
      sf::IntRect enemy_r = enemy->getRect();
      if (weapon_r.left >= enemy_r.left && weapon_r.width <= enemy_r.width &&
          weapon_r.top >= enemy_r.top && weapon_r.height <= enemy_r.height)
        return true;
    }
  }
  return false;
}

sf::Keyboard::Key Game::getKey() const { return mState; }

/*
 * Private methods
 */

void Game::ProcessInput() {
  sf::Time deltaTime = mClock.restart();
  mDeltaTime = deltaTime.asMilliseconds();
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      Shutdown();
  }
  mState = event.key.code;
}

void Game::UpdateGame() {
  for (auto entity : mEntities) {
    if (entity != nullptr)
      entity->Update();
  }
}

void Game::GenerateOutput() {
  mWindow.clear();
  for (const auto &entity : mEntities) {
    entity->Draw();
  }
  mWindow.display();
}

void Game::AddTexture(std::string &&name, std::string &&filename) {
  auto texture = std::make_shared<sf::Texture>();
  if (!texture->loadFromFile(filename)) {
    std::cerr << "Failed to load texture from file: " << filename << std::endl;
    return;
  }
  mTextures.emplace(name, std::move(texture));
}