#pragma once
#include <SFML/Graphics.hpp>

#include "TextureInfo.h"
#include "collision/Collider.h"

namespace engine {

class GameObject {
public:
    GameObject (sf::Vector2f pos, sf::Vector2f size);
    virtual ~GameObject () {};

    virtual void onLoad();
    virtual void Update(const float deltaTime);
    virtual void draw(sf::RenderWindow& window);

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;
    Collider getCollider();
protected:
    sf::RectangleShape body;
    TextureInfo* textureInfo;
    sf::Sprite sprite;
};

} // engine