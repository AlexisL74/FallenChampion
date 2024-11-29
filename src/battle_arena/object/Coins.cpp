#include "Coins.h"

#include <iostream>
#include "../../FallenChampion.h"

Coins::Coins(sf::Vector2f pos, sf::Vector2f scale) : Object(pos, scale) {
    this->scale = scale;
    textureInfo = game->getTexture("Coins");
    Coins::onLoad();
}

void Coins::onLoad() {
    sprite.addAnimation("base", textureInfo->texture, textureInfo->frameSize.x, textureInfo->frameSize.y, textureInfo->frameCount.x, 0.1f, 0);
    sprite.setAnimation("base");

    sprite.setScale(scale);
    sprite.setPosition(getPosition());

    sf::Vector2f bSize = sf::Vector2f(sf::Vector2f(textureInfo->frameSize.x * scale.x, textureInfo->frameSize.y * scale.y));

    body.setSize(bSize);
    body.setOrigin(bSize / 2.0f);
    Object::onLoad();
}

void Coins::applyEffect(Entity *entity) {
    game->addScore(value);
}
