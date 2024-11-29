#pragma once

#include <vector>
#include "Player.h"
#include "Arena.h"
#include "Enemy.h"
#include "HUD.h"
#include "Object.h"
#include "Waves.h"
#include "../engine/TextureInfo.h"
#include "weapon/projectiles/Projectile.h"

class Level {
public:
    Level(const sf::FloatRect& arenaBounds, const sf::Vector2f& playerPosition, const sf::Vector2f& scale);
    ~Level();

    void Update(const float deltaTime);
    void draw(sf::RenderWindow& window);

    Player* getPlayer() const { return player; }
    Arena* getArena() const { return arena; }
    sf::FloatRect getBounds() const { return arena->getBounds(); }

    std::vector<Enemy*> getEnemies() const { return enemies; }
    void spawnEnemies();
    void addEnemy(Enemy* enemy) { enemies.push_back(enemy); }
    void removeEnemy(Enemy* enemy) { enemies.erase(std::remove(enemies.begin(), enemies.end(), enemy), enemies.end()); }

    std::vector<Projectile*> getProjectiles() const { return projectiles; }
    void addProjectile(Projectile* projectile) { projectiles.push_back(projectile); }
    void removeProjectile(Projectile* projectile) { projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), projectile), projectiles.end()); }

    std::vector<Object*> getObjects() const { return objects; }
    void addObject(Object* object) { objects.push_back(object); }
    void removeObject(Object* object) { objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end()); }

    engine::TextureInfo* getTextureInfo(std::string textureName);

    int getScore() { return score; }
    void addScore(int score) { this->score += score; }

private:
    FallenChampion* game;
    Player* player;
    Arena* arena;
    HUD* hud;
    Waves* waveSystem;
    std::vector<Enemy*> enemies;
    std::vector<Projectile*> projectiles;
    std::vector<Object*> objects;
    int score = 0;
    sf::Vector2f scale;
    static std::map<std::string, engine::TextureInfo> texturesIndex;
    void loadTextures();
};