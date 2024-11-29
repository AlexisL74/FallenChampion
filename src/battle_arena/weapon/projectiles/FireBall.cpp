#include "FireBall.h"
#include "../../../FallenChampion.h"
#include <cmath>

void FireBall::onLoad() {
    if(!texture.loadFromFile("assets/sprite/weapon/projectile_fireball.png")) {
        std::cerr << "Cannot open weapon texture!\n";
    } else {
        sprite.addAnimation("base", texture, textureSize.x, textureSize.y, 5, 0.1f, 0);
        sprite.setAnimation("base");

        sprite.scale(scale);
        sprite.setPosition(getPosition());

        // Set the origin of the sprite to the center of the body
        sprite.setOrigin(textureSize.x * scale.x / 2.0f, (textureSize.y ) * scale.y / 2.0f);

        // Calculate the angle of the direction vector
        float angle = atan2(direction.y, direction.x) * 180 / M_PI;
        sprite.setRotation(angle);
    }
    body.setSize(sf::Vector2f(textureSize.x * scale.x, textureSize.y * scale.y));
    body.setOrigin(body.getSize() / 2.0f);
    game->addProjectile(this);
}

void FireBall::Update(const float deltaTime) {
    body.setPosition(body.getPosition() + direction * speed * deltaTime);

    sprite.updateAnimation(deltaTime);

    checkCollisions();
    Projectile::Update(deltaTime);
}

void FireBall::draw(sf::RenderWindow &window) {
    sprite.setPosition(getPosition()+body.getSize()/2.0f);
    window.draw(sprite);
    if(game->getDrawCollider()) getCollider().draw(window);
}

void FireBall::damageEnemy(Enemy *enemy) {
    enemy->takeDamage(damage);
}
