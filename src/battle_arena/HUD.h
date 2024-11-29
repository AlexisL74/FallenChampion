#pragma once

#include <SFML/Graphics.hpp>

#include "../engine/AnimatedSprite.h"

class FallenChampion;

class HUD {
public:
    HUD();
    void onLoad();
    void Update(const float deltaTime);
    void draw(sf::RenderWindow &window);
private:
    FallenChampion* game;

    sf::Font font;
    char scoreInfo[sizeof("Score: *******")];
    sf::Text scoreText;

    std::vector<engine::AnimatedSprite> hearts;
};