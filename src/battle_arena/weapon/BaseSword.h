#pragma once

#include "../Weapon.h"

class BaseSword : public Weapon{
public:
    BaseSword(const sf::Vector2f pos, const sf::Vector2f scale, const engine::GameObject* ref) : Weapon(pos, scale, ref) {
        BaseSword::onLoad();
    };
    void onLoad() override;
    void Update(const float deltaTime) override;
private:
    sf::Vector2i textureSize = sf::Vector2i(10, 21);
};
