#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "../engine/AnimatedSprite.h"
#include "../engine/GameObject.h"

class FallenChampion;

class Object : public engine::GameObject {
public:

    Object(sf::Vector2f pos, sf::Vector2f scale);
    ~Object() = default;
    void Update(const float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    void pickUp(Entity* entity);
    virtual void applyEffect(Entity* entity);

protected:
    FallenChampion* game;

    engine::AnimatedSprite sprite;
    sf::Vector2f scale;

    float ttl = 10.0f;
};