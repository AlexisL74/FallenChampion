#pragma once
#include "../Object.h"

class Coins : public Object{
public:
    Coins(sf::Vector2f pos, sf::Vector2f scale);

    void onLoad() override;
private:
    int value = 10;
    void applyEffect(Entity* entity) override;
};
