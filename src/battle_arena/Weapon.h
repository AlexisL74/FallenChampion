#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../engine/Scriptable.h"
#include "../engine/AnimatedSprite.h"
#include "../engine/GameObject.h"

class FallenChampion;

class Weapon : public engine::GameObject {
public:
    Weapon(const sf::Vector2f pos, const sf::Vector2f scale, const engine::GameObject* ref);
    void draw(sf::RenderWindow &window);
    virtual void onLoad() {
    };
    virtual void Update(const float deltaTime);
    virtual void attack() {
        std::cout<<"Attack\n";
    };

protected:
    FallenChampion* game;
    const engine::GameObject *ref;

    sf::Vector2f scale;
    float radius = 55.0f;
    float currentAngle = 0.0f;

    sf::Texture texture;
    engine::AnimatedSprite sprite;

};
