#pragma once

#include "Projectile.h"

class FallenChampion;

class FireBall : public Projectile {
public:
    FireBall(const sf::Vector2f pos, const sf::Vector2f scale, sf::Vector2f direction) : Projectile(pos, scale, direction) {
        FireBall::onLoad();
    };
    void onLoad() override;
    void Update(const float deltaTime) override;
    void draw(sf::RenderWindow &window) override;
    void damageEnemy(Enemy* enemy) override;
private:
    float damage = 10.0f;
    float speed = 500.0f;
    sf::Vector2i textureSize = sf::Vector2i(16, 16);
};