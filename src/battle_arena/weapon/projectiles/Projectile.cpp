#include "Projectile.h"
#include "../../../FallenChampion.h"

Projectile::Projectile(const sf::Vector2f pos, const sf::Vector2f scale, sf::Vector2f direction) : GameObject(pos, scale) {
    this->scale = scale;
    this->game = FallenChampion::getInstance();
    this->direction = direction;
    Projectile::onLoad();
}

void Projectile::draw(sf::RenderWindow &window) {
    sprite.setPosition(getPosition());
    window.draw(sprite);
    if(game->getDrawCollider()) getCollider().draw(window);
}

void Projectile::checkCollisions() {
    engine::Collider projectileCollider = getCollider();
    for (auto enemy : game->getEnemies()) {
        engine::Collider enemyCollider = enemy->getCollider();
        if (projectileCollider.checkCollision(enemyCollider, 0.0f)) {
            damageEnemy(enemy);
            game->removeProjectile(this);
            return;
        }
    }
}
void Projectile::Update(float deltaTime) {
    ttl -= deltaTime;
    if (ttl <= 0.0f) {
        std::cout<<"delete projectile"<<std::endl;
        game->removeProjectile(this);
        delete this;
    }
}

void Projectile::damageEnemy(Enemy *enemy) {
    std::cout<<"Damage enemy\n";
}
