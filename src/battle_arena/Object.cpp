#include "Object.h"
#include "../FallenChampion.h"

Object::Object(sf::Vector2f pos, sf::Vector2f scale): GameObject(pos, scale) {
    this->game = FallenChampion::getInstance();
    this->scale = scale;
    textureInfo = game->getTexture("HealthPotions");
    Object::onLoad();
}

void Object::Update(const float deltaTime) {
    ttl -= deltaTime;
    sprite.setPosition(getPosition());
    sprite.updateAnimation(deltaTime);
    if (ttl <= 0) {
        std::cout << "1 " << typeid(*this).name() << std::endl;
        game->removeObject(this);
        std::cout<<"2"<<std::endl;
        delete this;
        std::cout<<"3"<<std::endl;
    }
}
void Object::draw(sf::RenderWindow &window) {
    sprite.setPosition(getPosition());
    window.draw(sprite);
    if(game->getDrawCollider()) getCollider().draw(window);
    GameObject::draw(window);
}

void Object::pickUp(Entity *entity) {
    applyEffect(entity);
    game->removeObject(this);
    delete this;
}

void Object::applyEffect(Entity* entity) {
    std::cout<<"Object applied effect\n";
}
