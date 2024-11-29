#include "Enemy.h"
#include "../FallenChampion.h"
#include "../engine/Utils.h"
#include "object/Coins.h"
#include "object/HpPotions.h"

Enemy::Enemy(const sf::Vector2f pos, const sf::Vector2f scale) : Entity(pos, scale) {
    this->scale = scale;
    this->maxHealth = 20.0f;
    this->health = maxHealth;
    this->textureInfo = game->getTexture("Wogol");
    this->target = game->getPlayer();
    Enemy::onLoad();
}

void Enemy::onLoad() {
    Entity::onLoad();
}

void Enemy::Update(const float deltaTime) {
    sf::Vector2f targetPos = target->getPosition();
    sf::Vector2f direction = engine::Utils::normalize(targetPos - body.getPosition());
    if(direction != sf::Vector2f(0.0f, 0.0f)) {
        if (direction.x > 0) {
            sprite.setScale(scale.x, scale.y);
        } else if (direction.x < 0) {
            sprite.setScale(-scale.x, scale.y);
        }

        applyMovement(direction, deltaTime);
    }
    if(direction != sf::Vector2f(0.0f, 0.0f) && !isMoving) {
        isMoving = true;
        sprite.setAnimation("run");
    } else if(direction == sf::Vector2f(0.0f, 0.0f) && isMoving) {
        isMoving = false;
        sprite.setAnimation("idle");
    }

    Entity::Update(deltaTime);
}

void Enemy::checkCollisions(std::vector<Enemy *> otherCollider) {
    engine::Collider playerCollider = target->getCollider();
    getCollider().checkCollision(playerCollider, 0.0f);
    for(auto it: otherCollider) {
        if(it != this) {
            engine::Collider otherCollider = it->getCollider();
            getCollider().checkCollision(otherCollider, 0.0f);
        }
    }
}

void Enemy::onDeath() {
    loot();
    game->removeEnemy(this);
    delete this;
}
