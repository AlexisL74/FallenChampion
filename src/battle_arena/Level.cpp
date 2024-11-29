#include "Level.h"

#include <memory>

#include "../FallenChampion.h"
#include "enemies/Chort.h"
#include "enemies/Demon.h"
#include "enemies/Wogol.h"
#include "object/Coins.h"
#include "object/HpPotions.h"

Level::Level(const sf::FloatRect& arenaBounds, const sf::Vector2f& playerPosition, const sf::Vector2f& scale) : game(FallenChampion::getInstance()), scale(scale) {
    loadTextures();
    hud = new HUD();

    arena = new Arena(arenaBounds, scale);
    player = new Player(playerPosition, scale);

    waveSystem = new Waves(this);
}

Level::~Level() {
    delete player;
    delete arena;
    delete waveSystem;
    for (auto enemy : enemies) {
        delete enemy;
    }
    for (auto projectile: projectiles) {
        delete projectile;
    }
    for (auto object: objects) {
        delete object;
    }
}

void Level::spawnEnemies() {
    waveSystem->addEnemyType(new Chort(sf::Vector2f(0.0f, 0.0f), scale), 0.8f);
    waveSystem->addEnemyType(new Demon(sf::Vector2f(0.0f, 0.0f), scale), 0.15f);
    waveSystem->addEnemyType(new Wogol(sf::Vector2f(0.0f, 0.0f), scale), 0.05f);
}

engine::TextureInfo* Level::getTextureInfo(std::string textureName) {
    if (texturesIndex.empty()) {
        std::cout << "Textures not loaded" << std::endl;
    }
    auto it = texturesIndex.find(textureName);
    if (it != texturesIndex.end()) {
        return &it->second;
    } else {
        std::cerr << "Texture not found: " << textureName << std::endl;
        return nullptr;
    }
}

void Level::loadTextures() {
    engine::TextureInfo arenaTexture;
    if (!arenaTexture.texture.loadFromFile("assets/sprite/arena/Arena-01.png")) {
        std::cerr << "Failed to load Arena texture" << std::endl;
    }
    arenaTexture.frameSize = sf::Vector2u(688, 400);
    arenaTexture.frameCount = sf::Vector2u(6, 1);
    texturesIndex["Arena"] = arenaTexture;

    engine::TextureInfo playerTexture;
    if (!playerTexture.texture.loadFromFile("assets/sprite/knight_f/knight_f.png")) {
        std::cerr << "Failed to load Player texture" << std::endl;
    }
    playerTexture.frameSize = sf::Vector2u(16, 28);
    playerTexture.frameCount = sf::Vector2u(4, 2);
    texturesIndex["Player"] = playerTexture;

    engine::TextureInfo chortTexture;
    if (!chortTexture.texture.loadFromFile("assets/sprite/enemies/chort.png")) {
        std::cerr << "Failed to load Chort texture" << std::endl;
    }
    chortTexture.frameSize = sf::Vector2u(16, 23);
    chortTexture.frameCount = sf::Vector2u(4, 2);
    texturesIndex["Chort"] = chortTexture;

    engine::TextureInfo demonTexture;
    if (!demonTexture.texture.loadFromFile("assets/sprite/enemies/demon.png")) {
        std::cerr << "Failed to load Demon texture" << std::endl;
    }
    demonTexture.frameSize = sf::Vector2u(32, 36);
    demonTexture.frameCount = sf::Vector2u(4, 2);
    texturesIndex["Demon"] = demonTexture;

    engine::TextureInfo wogolTexture;
    if (!wogolTexture.texture.loadFromFile("assets/sprite/enemies/wogol.png")) {
        std::cerr << "Failed to load Wogol texture" << std::endl;
    }
    wogolTexture.frameSize = sf::Vector2u(16, 23);
    wogolTexture.frameCount = sf::Vector2u(4, 2);
    texturesIndex["Wogol"] = wogolTexture;

    engine::TextureInfo heartTexture;
    if (!heartTexture.texture.loadFromFile("assets/sprite/ui/hearts.png")) {
        std::cerr << "Failed to load Heart texture" << std::endl;
    }
    heartTexture.frameSize = sf::Vector2u(13, 12);
    heartTexture.frameCount = sf::Vector2u(1, 3);
    texturesIndex["Heart"] = heartTexture;

    engine::TextureInfo hpPotionTexture;
    if (!hpPotionTexture.texture.loadFromFile("assets/sprite/objects/hp_potions.png")) {
        std::cerr << "Failed to load HealthPotions texture" << std::endl;
    }
    hpPotionTexture.frameSize = sf::Vector2u(16, 16);
    hpPotionTexture.frameCount = sf::Vector2u(1, 2);
    texturesIndex["HealthPotions"] = hpPotionTexture;

    engine::TextureInfo coinTexture;
    if (!coinTexture.texture.loadFromFile("assets/sprite/objects/coins.png")) {
        std::cerr << "Failed to load Coins texture" << std::endl;
    }
    coinTexture.frameSize = sf::Vector2u(6, 7);
    coinTexture.frameCount = sf::Vector2u(4, 1);
    texturesIndex["Coins"] = coinTexture;

    for (const auto& it : texturesIndex) {
        std::cout << "Loaded texture: " << it.first << std::endl;
    }
}

void Level::Update(const float deltaTime) {
    player->Update(deltaTime);
    arena->Update(deltaTime);
    for (auto enemy : enemies) {
        enemy->Update(deltaTime);
    }
    for (auto projectile : projectiles) {
        projectile->Update(deltaTime);
    }
    for (auto object : objects) {
        object->Update(deltaTime);
    }
    waveSystem->Update(deltaTime);

    engine::Collider playerCollider = player->getCollider();
    for (auto enemy : enemies) {
        engine::Collider enemyCollider = enemy->getCollider();
        // Check Collision between player and enemy
        if (playerCollider.checkCollision(enemyCollider, 1.0f)) {
            player->takeDamage(enemy->getDamage());
        }

        // Check Collision between enemies
        for (auto it : enemies) {
            if (enemy != it) {
                engine::Collider otherEnemyCollider = it->getCollider();
                enemyCollider.checkCollision(otherEnemyCollider, 0.0f);
            }
        }

        // Check Collision between enemy and player projectiles
        for (auto projectile : projectiles) {
            if (projectile->getCollider().checkCollision(enemyCollider, 0.0f)) {
                projectile->damageEnemy(enemy);
            }
        }
    }

    for (auto object: objects) {
        engine::Collider objectCollider = object->getCollider();
        if (playerCollider.checkCollision(objectCollider, 1.0f)) {
            object->pickUp(player);
        }

    }
    // Update the view's center to the player position
    game->getView().setCenter(player->getPosition());
    game->getWindow().setView(game->getView());
    hud->Update(deltaTime);
}

void Level::draw(sf::RenderWindow& window) {
    arena->draw(window);
    for (auto enemy : enemies) {
        enemy->draw(window);
    }
    for (auto projectile : projectiles) {
        projectile->draw(window);
    }
    for (auto object : objects) {
        object->draw(window);
    }
    player->draw(window);
    hud->draw(window);
}

std::map<std::string, engine::TextureInfo> Level::texturesIndex = std::map<std::string, engine::TextureInfo>();