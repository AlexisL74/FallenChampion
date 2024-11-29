#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>

namespace engine {
struct Animation {
    const sf::Texture* texture;
    int frameWidth;
    int frameHeight;
    int frameCount;
    float frameDuration;
    int startRowPixel;
};

class AnimatedSprite : public sf::Sprite {
public:
    AnimatedSprite() {};
    ~AnimatedSprite() = default;
    void addAnimation(const std::string name, const sf::Texture& texture, int frameWidth, int frameHeight, int frameCount, float frameDuration, int startRowPixel);
    void setAnimation(const std::string name);
    void updateAnimation(const float deltaTime);
    void setPosition(const sf::Vector2f& position);
    void drawDebug(sf::RenderWindow& window);
private:
    sf::IntRect currentFrame;
    std::pmr::unordered_map<std::string, Animation> animations;
    Animation* currentAnimation;
    float elapsedTime = 0.0f;
};
} // engine
