#pragma once

#include <SFML/Graphics.hpp>

class FallenChampion;

class StartScreen {
public:
    StartScreen(FallenChampion* game);
    void handleEvent(sf::Event& event);
    void Update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    FallenChampion* game;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Font titleFont;
    sf::Text title;
    sf::Text startButton;
    sf::Text exitButton;
    bool isStartButtonHovered;
    bool isExitButtonHovered;
};