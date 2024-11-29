#include <iostream>

#include "AnimatedSprite.h"

namespace engine {
    void AnimatedSprite::addAnimation(const std::string name, const sf::Texture& texture, int frameWidth, int frameHeight, int frameCount, float frameDuration, int rowStartPixel) {
        animations[name] = Animation{&texture, frameWidth, frameHeight, frameCount, frameDuration, rowStartPixel};
    }

    void AnimatedSprite::setAnimation(const std::string name) {
        auto it = animations.find(name);
        if(it != animations.end()) {
            currentAnimation = &it->second;
            currentFrame = sf::IntRect(0, currentAnimation->startRowPixel * currentAnimation->frameHeight, currentAnimation->frameWidth, currentAnimation->frameHeight);
            this->setTexture(*currentAnimation->texture);
            this->setTextureRect(currentFrame);
        }
    }

    void AnimatedSprite::updateAnimation(const float deltaTime) {
        if(currentAnimation) {
            elapsedTime += deltaTime;
            if(elapsedTime >= currentAnimation->frameDuration) {
                currentFrame.left += currentAnimation->frameWidth;
                if(currentFrame.left >= currentAnimation->frameWidth * currentAnimation->frameCount) {
                    currentFrame.left = 0;
                }
                this->setTextureRect(currentFrame);
                elapsedTime = 0.0f;
            }
        }
    }

    void AnimatedSprite::setPosition(const sf::Vector2f &position) {
        sf::Vector2f scale = this->getScale();
        sf::Vector2f offset = sf::Vector2f(-(currentAnimation->frameWidth / 2) * scale.x, -(currentAnimation->frameHeight / 2) * scale.y);
        this->sf::Sprite::setPosition(offset + position);
    }

    void AnimatedSprite::drawDebug(sf::RenderWindow &window) {
        sf::FloatRect colliderBounds = this->getGlobalBounds();
        sf::RectangleShape colliderShape(sf::Vector2f(colliderBounds.width, colliderBounds.height));
        colliderShape.setPosition(colliderBounds.left, colliderBounds.top);
        colliderShape.setFillColor(sf::Color(0, 0, 0, 0)); // Transparent fill
        colliderShape.setOutlineColor(sf::Color::Red); // Red outline
        colliderShape.setOutlineThickness(1.0f);
        window.draw(colliderShape);
    }
} // engine