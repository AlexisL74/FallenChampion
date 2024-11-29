#pragma once
#include <SFML/Graphics/Texture.hpp>

namespace engine {
    struct TextureInfo {
        sf::Texture texture;
        sf::Vector2u frameSize;
        sf::Vector2u frameCount;
    };
} // engine