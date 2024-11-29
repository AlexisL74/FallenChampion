#pragma once

#include <SFML/System/Vector2.hpp>

class Scriptable {
public:
    Scriptable(): Scriptable(sf::Vector2f(0.0f, 0.0f)) {};
    Scriptable(sf::Vector2f pos) : position(pos) { Scriptable::onLoad(); };
    virtual ~Scriptable() {};

    virtual void onLoad() {};  // Called when the script is loaded
    virtual void Update(const float deltaTime) {}; // Called every frame
    virtual void draw(sf::RenderWindow& window) {};
    sf::Vector2f getPosition() const { return position; }
    void setPosition(sf::Vector2f pos) { position = pos; }
    sf::FloatRect getBoundingBox() const { return sf::FloatRect(position.x, position.y, 0.0f, 0.0f); } // TODO: Temporaire
protected:
    sf::Vector2f position;
};