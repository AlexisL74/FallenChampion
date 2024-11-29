#include "Collider.h"
#include <iostream>

namespace engine {
    bool Collider::checkCollision(Collider &other, float push) {
        sf::Vector2f otherPosition = other.getPosition();
        sf::Vector2f otherHalfSize = other.getHalfSize();
        sf::Vector2f thisPosition = getPosition();
        sf::Vector2f thisHalfSize = getHalfSize();

        float deltaX = otherPosition.x - thisPosition.x;
        float deltaY = otherPosition.y - thisPosition.y;

        float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
        float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

        if (intersectX < 0.0f && intersectY < 0.0f) {
            //push = std::min(std::max(push, 0.0f), 1.0f); // Clamp the value

            if(abs(intersectX) > abs(intersectY)) {
                if(deltaX > 0.0f) {
                    move(intersectX * (1.0f - push) * pushForce, 0.0f);
                    other.move(-intersectX * push * pushForce, 0.0f);
                }
                else {
                    move(-intersectX * (1.0f - push) * pushForce, 0.0f);
                    other.move(intersectX * push * pushForce, 0.0f);
                }
            } else {
                if(deltaY > 0.0f) {
                    move(0.0f, intersectY * (1.0f - push) * pushForce);
                    other.move(0.0f, -intersectY * push * pushForce);
                }
                else {
                    move(0.0f, -intersectY * (1.0f - push) * pushForce);
                    other.move(0.0f, intersectY * push * pushForce);
                }
            }
            return true;
        }
        return false;
    }

    void Collider::draw(sf::RenderWindow &window) {
        body.setFillColor(sf::Color(0, 0, 0, 0));
        // std::cout<<"Drawing collider\n";
        body.setOutlineColor(sf::Color::Green);
        body.setOutlineThickness(1.0f);
        window.draw(body);
    }
}