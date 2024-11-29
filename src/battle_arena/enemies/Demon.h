#pragma once
#include "../Enemy.h"

class FallenChampion;

class Demon : public Enemy{
public:
    Demon(const sf::Vector2f pos, const sf::Vector2f scale);
    void loot() override;
};
