#include "RedMagicStaff.h"
#include "../../FallenChampion.h"
#include "projectiles/FireBall.h"
#include <cmath>

void RedMagicStaff::onLoad() {
    if(!texture.loadFromFile("assets/sprite/weapon/weapon_red_magic_staff.png")) {
        std::cerr << "Cannot open weapon texture!\n";
    } else {
        sprite.addAnimation("base", texture, textureSize.x, textureSize.y, 1, 0.1f, 0);
        sprite.addAnimation("mk-1", texture, textureSize.x, textureSize.y, 1, 0.1f, 1);
        sprite.setAnimation("base");

        sprite.scale(scale);
        sprite.setPosition(getPosition());
        sprite.setOrigin(body.getSize() / 2.0f);
    }
    body.setSize(sf::Vector2f(textureSize.x * scale.x, textureSize.y * scale.y));
}

void RedMagicStaff::Update(const float deltaTime) {
    Weapon::Update(deltaTime);
}

void RedMagicStaff::attack() {
    sf::Vector2f projectileDirection((float)cos(currentAngle), (float)sin(currentAngle));
    new FireBall(getPosition(), sf::Vector2f(1.0f, 1.0f), projectileDirection);
}