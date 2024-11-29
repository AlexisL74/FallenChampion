#pragma once
#include <SFML/Graphics.hpp>

namespace engine {
    class Collider {
    public:
        Collider(sf::RectangleShape& body) : body(body) {};
        ~Collider() = default;

        void move(float dx, float dy) { body.move(dx, dy); }

        bool checkCollision(Collider& other, float push);
        sf::Vector2f getPosition() const { return body.getPosition(); }
        sf::Vector2f getHalfSize() const { return body.getSize() / 2.0f; }

        void draw(sf::RenderWindow &window);
    private:
        sf::RectangleShape& body;

        float pushForce = 0.17f;
    };
}