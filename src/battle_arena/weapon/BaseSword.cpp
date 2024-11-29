#include "BaseSword.h"
#include "../../FallenChampion.h"


void BaseSword::onLoad() {
    if(!texture.loadFromFile("assets/sprite/weapon/weapon_regular_sword.png")) {
        std::cerr << "Cannot open weapon texture!\n";
    } else {
        sprite.addAnimation("base", texture, textureSize.x, textureSize.y, 1, 0.1f, 0);
        sprite.setAnimation("base");

        sprite.scale(scale);
        sprite.setPosition(getPosition());
        sprite.setOrigin(body.getSize() / 2.0f);
    }
    body.setSize(sf::Vector2f(textureSize.x * scale.x, textureSize.y * scale.y));
};

void BaseSword::Update(const float deltaTime) {
    Weapon::Update(deltaTime);
};