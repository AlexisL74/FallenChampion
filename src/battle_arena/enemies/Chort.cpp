#include "Chort.h"
#include "../../FallenChampion.h"
#include "../object/Coins.h"
#include "../object/HpPotions.h"
#include "../../engine/Utils.h"

Chort::Chort(const sf::Vector2f pos, const sf::Vector2f scale) : Enemy(pos, scale) {
    this->scale = scale;
    this->maxHealth = 20.0f;
    this->health = maxHealth;
    this->moveSpeed = 100.0f;
    textureInfo = game->getTexture("Chort");
    Enemy::onLoad();
}

void Chort::loot() {
    float random = engine::Utils::random(0.0f, 1.0f);
    if (random < 0.05) {
        game->addObject(new HpPotions(2, getPosition(), scale));
    }
    else if (random < 0.1) {
        game->addObject(new HpPotions(1, getPosition(), scale));
    }
    else if (random < 0.5) {
        game->addObject(new Coins(getPosition(), scale));
    }
}