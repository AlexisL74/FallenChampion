#include "Entity.h"
#include "../FallenChampion.h"

Entity::Entity(const sf::Vector2f pos, const sf::Vector2f scale) : GameObject(pos, scale) {
    this->game = FallenChampion::getInstance();
    this->scale = scale;
    textureInfo = game->getTexture("Wogol");
    Entity::onLoad();
}

void Entity::onLoad() {
    sprite.addAnimation("idle", textureInfo->texture, textureInfo->frameSize.x, textureInfo->frameSize.y, textureInfo->frameCount.x, 0.1f, 0);
    sprite.addAnimation("run", textureInfo->texture, textureInfo->frameSize.x, textureInfo->frameSize.y, textureInfo->frameCount.x, 0.1f, 1);
    sprite.setAnimation("idle");

    sprite.setScale(scale);
    sprite.setPosition(body.getPosition());

    sf::Vector2f bSize = sf::Vector2f(sf::Vector2f(textureInfo->frameSize.x * scale.x, textureInfo->frameSize.y * scale.y));

    body.setSize(bSize);
    body.setOrigin(bSize / 2.0f);
}

void Entity::Update(const float deltaTime) {
    sprite.updateAnimation(deltaTime);
    invisibilityTimer += deltaTime;
    if (invisibilityTimer >= invisibilityDuration) {
        sprite.setColor(sf::Color(255, 255, 255, 255));
    }
    GameObject::Update(deltaTime);
}

void Entity::draw(sf::RenderWindow &window) {
    sprite.setPosition(body.getPosition());
    window.draw(sprite);
    if(game->getDrawCollider()) getCollider().draw(window);
}

void Entity::healing(const float heal) {
    health += heal;
    if (health > maxHealth) {
        health = maxHealth;
    }
    // std::cout<<"hp: "<<health<<"/"<<maxHealth<<std::endl;
}

void Entity::takeDamage(const float damage) {
    if (invisibilityDuration < invisibilityTimer) {
        health -= damage;
        invisibilityTimer = 0.0f;
        sprite.setColor(sf::Color(255, 128, 128, 128));
        if (health <= 0) {
            onDeath();
        }
    }
}

void Entity::onDeath() {
    std::cout<<"Entity died\n";
}

void Entity::applyMovement(const sf::Vector2f &movement, const float deltaTime) {
    sf::Vector2f moveVector = movement * moveSpeed * deltaTime;

    // Check the bounds of the arena
    sf::FloatRect playerBounds = sprite.getGlobalBounds();

    sf::FloatRect arenaBounds = game->getArenaBounds();
    if (playerBounds.left + moveVector.x < arenaBounds.left) {
        moveVector.x = arenaBounds.left - playerBounds.left;
    } else if (playerBounds.left + playerBounds.width + moveVector.x > arenaBounds.left + arenaBounds.width) {
        moveVector.x = (arenaBounds.left + arenaBounds.width) - (playerBounds.left + playerBounds.width);
    }
    if (playerBounds.top + moveVector.y < arenaBounds.top) {
        moveVector.y = arenaBounds.top - playerBounds.top;
    } else if (playerBounds.top + playerBounds.height + moveVector.y > arenaBounds.top + arenaBounds.height) {
        moveVector.y = (arenaBounds.top + arenaBounds.height) - (playerBounds.top + playerBounds.height);
    }

    body.setPosition((body.getPosition()+ moveVector));}
