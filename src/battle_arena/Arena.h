#pragma once

#include <SFML/Graphics.hpp>
#include "../engine/Scriptable.h"
#include "../engine/AnimatedSprite.h"
#include "../engine/GameObject.h"
#include "../engine/collision/Collider.h"

class FallenChampion;

class Arena : public Scriptable{
public:
    Arena(const sf::FloatRect bounds, sf::Vector2f scale);
    ~Arena() = default;

    void onLoad() override;
    void Update(const float deltaTime) override;
    void draw(sf::RenderWindow &window) override;

    sf::FloatRect getBounds() const { return arenaBounds; }
    std::vector<engine::Collider> getColliders();
private:
    FallenChampion* game;

    sf::FloatRect arenaBounds;
    std::vector<sf::RectangleShape> colliders;

    sf::Vector2f scale;
    engine::AnimatedSprite sprite;
};
