#pragma once
#include "../Object.h"

class HpPotions : public Object {
public:
    HpPotions(int level, sf::Vector2f pos, sf::Vector2f scale);

    void onLoad() override;
private:
    int level;
    void applyEffect(Entity* entity) override;
};