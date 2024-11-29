#pragma once

#include <vector>
#include <bits/unique_ptr.h>

#include "Enemy.h"
#include "enemies/Chort.h"
#include "enemies/Wogol.h"
#include "enemies/Demon.h"

class Level;

class Waves {
public:
    Waves(Level* level);
    ~Waves() = default;

    void Update(const float deltaTime);
    void startNextWave();

    int getCurrentWave() const { return currentWave; }
    bool isWaveInProgress() const { return waveInProgress; }

    void addEnemyType(Enemy* enemy, float spawnChance);

private:
    Level* level;
    int currentWave;
    bool waveInProgress;
    float waveTimer;
    int enemiesToSpawn;
    int enemiesPerWave;
    float timeBetweenWaves;

    std::vector<std::pair<Enemy*, float>> enemyTypes;

    void spawnWave();
};
