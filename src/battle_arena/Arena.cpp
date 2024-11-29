#include "Arena.h"
#include "../FallenChampion.h"
#include <iostream>

Arena::Arena(const sf::FloatRect bounds, sf::Vector2f scale)  : arenaBounds(bounds), scale(scale), game(FallenChampion::getInstance()) { Arena::onLoad(); };

void Arena::onLoad() {
    Scriptable::onLoad();
    engine::TextureInfo* texture = game->getTexture("Arena");

    sprite.addAnimation("idle", texture->texture, texture->frameSize.x, texture->frameSize.y, texture->frameCount.x, 0.1f, 0);
    sprite.setAnimation("idle");
    sprite.scale(scale);
    sprite.setPosition(sf::Vector2f(0.0f, 0.0f));

    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    arenaBounds = sf::FloatRect(spriteBounds.left+6.0f, spriteBounds.top+32.0f, spriteBounds.width-12.0f, spriteBounds.height-38.0f);

    // // Define four colliders
    // sf::RectangleShape topCollider(sf::Vector2f(arenaBounds.width, 10.0f));
    // topCollider.setPosition(arenaBounds.left, arenaBounds.top);
    // colliders.push_back(topCollider); // Top
    //
    // sf::RectangleShape bottomCollider(sf::Vector2f(arenaBounds.width, 10.0f));
    // bottomCollider.setPosition(arenaBounds.left, arenaBounds.top + arenaBounds.height - 10.0f);
    // colliders.push_back(bottomCollider); // Bottom
    //
    // sf::RectangleShape leftCollider(sf::Vector2f(10.0f, arenaBounds.height));
    // leftCollider.setPosition(arenaBounds.left, arenaBounds.top);
    // colliders.push_back(leftCollider); // Left
    //
    // sf::RectangleShape rightCollider(sf::Vector2f(10.0f, arenaBounds.height));
    // rightCollider.setPosition(arenaBounds.left + arenaBounds.width - 10.0f, arenaBounds.top);
    // colliders.push_back(rightCollider); // Right
}

void Arena::Update(const float deltaTime) {
    Scriptable::Update(deltaTime);
    sprite.updateAnimation(deltaTime);
}

void Arena::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    // for (const auto& collider : colliders) {
    //     sf::RectangleShape rect = collider;
    //     rect.setFillColor(sf::Color(0, 255, 0, 100)); // Semi-transparent red
    //     window.draw(rect);
    // }
}

std::vector<engine::Collider> Arena::getColliders() {
    std::vector<engine::Collider> colliders;
    for (auto& collider : this->colliders) {
        colliders.push_back(engine::Collider(collider));
    }
    return colliders;
}
