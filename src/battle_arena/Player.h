#pragma once
#include "Weapon.h"
#include "../engine/AnimatedSprite.h"
#include "Entity.h"

class FallenChampion;
class Player : public Entity {
public:
    Player(const sf::Vector2f pos, sf::Vector2f size);
    ~Player() {};

    void onLoad() override;
    void Update(const float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void onDeath() override;
private:
    Weapon* weapon;

    bool isRMbtnPressed = false;

    sf::Vector2f getMovementInput();
};
