#pragma once
#include "../engine/GameObject.h"
#include "../engine/AnimatedSprite.h"
#include "../engine/TextureInfo.h"

class FallenChampion;

class Entity : public engine::GameObject{
public:
    Entity(const sf::Vector2f pos, const sf::Vector2f scale);
    ~Entity() = default;

    void onLoad() override;
    void Update(const float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    float getHealth() const { return health; };
    void healing(const float heal);
    float getMaxHealth() const { return maxHealth; };
    void takeDamage(const float damage);
    virtual void onDeath();
protected:
    FallenChampion* game;
    float maxHealth = 20.0f;
    float health = maxHealth;

    float moveSpeed = 100.0f;
    sf::Vector2f scale;

    engine::AnimatedSprite sprite;

    float invisibilityTimer = 0.0f;
    float invisibilityDuration = 0.3f;

    bool isMoving = false;
    void applyMovement(const sf::Vector2f& movement, const float deltaTime);
};