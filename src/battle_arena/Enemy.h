#pragma once

#include "Entity.h"
#include "Player.h"

class FallenChampion;

class Enemy : public Entity {
public:
    Enemy(const sf::Vector2f pos, const sf::Vector2f scale);
    ~Enemy() = default;

    void onLoad() override;
    void Update(const float deltaTime) override;
    void checkCollisions(std::vector<Enemy*> otherCollider);
    void onDeath() override;

    float getDamage() const { return damage; }
    virtual void loot() {std::cout<<"Je devrais pas apparaître"<<std::endl;};
protected:
    Player* target;

    float damage = 10.0f;
};