#pragma once
#include "../Enemy.h"

class FallenChampion;

class Chort : public Enemy{
public:
    Chort(const sf::Vector2f pos, const sf::Vector2f scale);
    void loot() override;
};