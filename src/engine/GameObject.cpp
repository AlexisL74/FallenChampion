#include "GameObject.h"
#include <iostream>
namespace engine {
    GameObject::GameObject(sf::Vector2f pos, sf::Vector2f size) {
        body.setPosition(pos);
        body.setSize(size);
    }

    void GameObject::onLoad() {
    }

    void GameObject::Update(const float deltaTime) {
    }

    void GameObject::draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }

    void GameObject::setPosition(sf::Vector2f pos) {
        body.setPosition(pos);
    }

    sf::Vector2f GameObject::getPosition() const {
        return body.getPosition();
    }

    engine::Collider GameObject::getCollider() {
        return engine::Collider(body);
    }
} // engine