#include "HpPotions.h"
#include "../../FallenChampion.h"

HpPotions::HpPotions(int level, sf::Vector2f pos, sf::Vector2f scale) : Object(pos, scale) {
    this->scale = scale;
    this->level = level;
    textureInfo = game->getTexture("HealthPotions");
    HpPotions::onLoad();
}

void HpPotions::onLoad() {
    sprite.addAnimation("nv1", textureInfo->texture, textureInfo->frameSize.x, textureInfo->frameSize.y, textureInfo->frameCount.x, 0.1f, 0);
    sprite.addAnimation("nv2", textureInfo->texture, textureInfo->frameSize.x, textureInfo->frameSize.y, textureInfo->frameCount.x, 0.1f, 1);
    if (level == 1) {
        sprite.setAnimation("nv1");
    } else {
        sprite.setAnimation("nv2");
    }

    sprite.setScale(scale);
    sprite.setPosition(getPosition());

    sf::Vector2f bSize = sf::Vector2f(sf::Vector2f(textureInfo->frameSize.x * scale.x, textureInfo->frameSize.y * scale.y));

    body.setSize(bSize);
    body.setOrigin(bSize / 2.0f);
    Object::onLoad();
}

void HpPotions::applyEffect(Entity* entity) {
    entity->healing(10.0f*level);
}
