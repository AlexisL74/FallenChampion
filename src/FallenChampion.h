#pragma once

#include <SFML/Graphics.hpp>
#include "Interfaces.h"
#include "battle_arena/Player.h"
#include "battle_arena/Arena.h"
#include "battle_arena/Enemy.h"
#include "battle_arena/Level.h"
#include "battle_arena/weapon/projectiles/Projectile.h"
#include "StartScreen.h"
#include "GameOver.h"

class FallenChampion {
public:
    static FallenChampion* getInstance();
    void run();

    const static int HEIGHT = 1440;
    const static int WIDTH = 2160;

    bool getHasFocus() const { return hasfocus; };
    sf::FloatRect getArenaBounds() const { return level->getBounds(); };
    Player* getPlayer() const { return level->getPlayer(); };
    sf::RenderWindow& getWindow() { return window; };
    sf::View& getView() { return view; };
    std::vector<Enemy*> getEnemies() const { return level->getEnemies(); };
    void removeEnemy(Enemy* enemy) { level->removeEnemy(enemy); };
    bool getDrawCollider() const { return drawCollider; };
    std::vector<Projectile*> getProjectiles() const { return level->getProjectiles(); };
    void addProjectile(Projectile* projectile) { level->addProjectile(projectile); };
    void removeProjectile(Projectile* projectile) { level->removeProjectile(projectile); };
    void addObject(Object* object) { level->addObject(object); };
    void removeObject(Object* object) { level->removeObject(object); };
    int getScore() { return level->getScore(); }
    void addScore(int score) { level->addScore(score); }
    engine::TextureInfo* getTexture(std::string textureName) { return level->getTextureInfo(textureName); };
    void startGame();
    void gameOver();
private:
    FallenChampion();
    ~FallenChampion() = default;
    FallenChampion(const FallenChampion&) = delete;
    FallenChampion& operator=(const FallenChampion&) = delete;

    static FallenChampion* instance;
    sf::RenderWindow window;
    sf::RenderStates states;
    sf::View view;
    Interfaces interface;

    bool hasfocus = true;
    bool drawCollider = false;

    Level* level;

    void init_window(const std::string windowName, const int windowWidth, const int windowHeight);
    void GUI_init(const float dt) const;

    bool isGameStarted = false;
    StartScreen* startScreen;
    GameOver* gameOverScreen;
    bool isGameOver;
};