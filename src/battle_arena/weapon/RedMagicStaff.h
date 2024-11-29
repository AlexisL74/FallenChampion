#pragma once

#include "../Weapon.h"

class FallenChampion;
class RedMagicStaff : public Weapon{
public:
    RedMagicStaff(const sf::Vector2f pos, const sf::Vector2f scale, const engine::GameObject* ref) : Weapon(pos, scale, ref) {
        this->radius = 65.0;
        RedMagicStaff::onLoad();
    }

    void onLoad() override;
    void Update(const float deltaTime) override;
    void attack() override;
private:
    sf::Vector2i textureSize = sf::Vector2i(8, 30);
};