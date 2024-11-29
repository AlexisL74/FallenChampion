#include "Utils.h"
#include <cmath>

sf::Texture engine::Utils::load_texture(const std::string &path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path, sf::IntRect(0, 0, 29, 27))) {
        throw std::runtime_error("Cannot open texture!\n");
    }
    return texture;
}
sf::Vector2f engine::Utils::normalize(const sf::Vector2f &vector) {
    float length = sqrt(vector.x * vector.x + vector.y * vector.y);
    if (length != 0) {
        return sf::Vector2f(vector.x / length, vector.y / length);
    }
    return vector;
}

float engine::Utils::random(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}
