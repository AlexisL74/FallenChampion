#pragma once
#include "../Enemy.h"

class FallenChampion;

class Wogol : public Enemy{
public:
    Wogol(const sf::Vector2f pos, const sf::Vector2f scale);
    void loot() override;
};
