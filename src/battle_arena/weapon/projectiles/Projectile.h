#pragma once
#include "../../Enemy.h"
#include "../../../engine/GameObject.h"
#include "../../../engine/AnimatedSprite.h"

class FallenChampion;
class Projectile : public engine::GameObject {
public:
    Projectile(const sf::Vector2f pos, const sf::Vector2f scale, sf::Vector2f direction);
    void draw(sf::RenderWindow &window);
    void checkCollisions();
    virtual void damageEnemy(Enemy* enemy);
    virtual void Update(float deltaTime);

protected:
    float ttl = 5.0f;
    float damage = 10.0f;
    float speed = 500.0f;
    sf::Vector2i textureSize = sf::Vector2i(64, 32);
    sf::Texture texture;
    engine::AnimatedSprite sprite;

    sf::Vector2f direction;

    sf::Vector2f scale;
    FallenChampion* game;
};
