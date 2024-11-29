//
// Created by alleo on 26/11/2024.
//

#include "Waves.h"
#include "Level.h"
#include "../FallenChampion.h"
#include "../engine/Utils.h"

Waves::Waves(Level *level) : level(level), currentWave(0), enemiesPerWave(5), timeBetweenWaves(5.0f), waveTimer(0.0f), waveInProgress(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Waves::Update(const float deltaTime) {
    if (!waveInProgress) {
        waveTimer += deltaTime;
        if (waveTimer >= timeBetweenWaves) {
            startNextWave();
        }
    } else {
        if (level->getEnemies().empty()) {
            waveInProgress = false;
            waveTimer = 0.0f;
        }
    }
}

void Waves::startNextWave() {
    currentWave++;
    enemiesPerWave += 2;
    spawnWave();
    waveInProgress = true;
}

void Waves::addEnemyType(Enemy *enemy, float spawnChance) {
    enemyTypes.push_back(std::make_pair(enemy, spawnChance));
}

void Waves::spawnWave() {
    for (int i = 0; i < enemiesPerWave; ++i) {
        sf::Vector2f position(rand() % static_cast<int>(level->getBounds().width), rand() % static_cast<int>(level->getBounds().height));
        float random = engine::Utils::random(0.0f, 1.0f);
        if (random < 0.05) {
            Enemy* newEnemy = new Demon(position, sf::Vector2f(2.0f, 2.0f));
            newEnemy->setPosition(position);
            level->addEnemy(newEnemy);
        } else if (random < 0.1) {
            Enemy* newEnemy = new Wogol(position, sf::Vector2f(2.0f, 2.0f));
            newEnemy->setPosition(position);
            level->addEnemy(newEnemy);
        } else {
            Enemy* newEnemy = new Chort(position, sf::Vector2f(2.0f, 2.0f));
            newEnemy->setPosition(position);
            level->addEnemy(newEnemy);
        }

    }
}