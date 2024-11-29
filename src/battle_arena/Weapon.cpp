#include "Weapon.h"
#include "../FallenChampion.h"
#include <cmath>

Weapon::Weapon(const sf::Vector2f pos, const sf::Vector2f scale, const engine::GameObject *ref) : GameObject(pos, scale) {
    this->ref = ref;
    this->scale = scale;
    this->game = FallenChampion::getInstance();
    Weapon::onLoad();
}

void Weapon::draw(sf::RenderWindow &window) {
    sprite.setPosition(getPosition()+body.getSize()/2.0f);
    window.draw(sprite);
    if(game->getDrawCollider()) getCollider().draw(window);
}

void Weapon::Update(const float deltaTime) {
    sf::Vector2f weaponPosition = ref->getPosition();
    sf::Vector2f mousePosition = game->getWindow().mapPixelToCoords(sf::Mouse::getPosition(game->getWindow()));
    currentAngle = atan2(mousePosition.y - weaponPosition.y, mousePosition.x - weaponPosition.x);
    float angle = currentAngle * 180 / M_PI + 90;

    // Calculate the new position of the weapon based on the angle
    sf::Vector2f offset((radius * cos((angle - 90) * M_PI / 180)), (radius * sin((angle - 90) * M_PI / 180))); // TODO: Fix the offset that is not right
    sprite.setPosition(weaponPosition + offset);
    body.setPosition(weaponPosition + offset);
    body.setRotation(angle);
    sprite.setRotation(angle);
    sprite.updateAnimation(deltaTime);
}
