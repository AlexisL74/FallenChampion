#pragma once
#include <string>

#include <SFML/Graphics.hpp>

namespace engine {
    class Utils {
    public:
        static sf::Texture load_texture(const std::string &path);
        static sf::Vector2f normalize(const sf::Vector2f &vector);
        static float random(float min, float max);
    };
}
