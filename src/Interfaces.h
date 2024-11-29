#pragma once

#include <SFML/Graphics.hpp>

class FallenChampion;

class Interfaces {
public:
    Interfaces(FallenChampion* ba) : ba(ba) {
        onLoad();
    };
    void onLoad();
    void Update(const float deltaTime);
    void draw(sf::RenderWindow &window);
private:
    FallenChampion* ba;

    sf::Font font;

    char frameInfoString[sizeof("FPS: *****.*, Frame time: *.*****")];
    sf::Text fpsText;
    void fpsGUI(const float dt);
};
