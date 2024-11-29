#include "StartScreen.h"
#include "FallenChampion.h"

StartScreen::StartScreen(FallenChampion* game) : game(game), isStartButtonHovered(false), isExitButtonHovered(false) {
    if (!backgroundTexture.loadFromFile("assets/start_screen_background.png")) {
        std::cerr << "Failed to load start screen background texture" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setColor(sf::Color(172, 172, 172, 255));
    backgroundSprite.setScale(game->getWindow().getSize().x / backgroundSprite.getLocalBounds().width, game->getWindow().getSize().y / backgroundSprite.getLocalBounds().height);
    font.loadFromFile("assets/font/PixeloidSans.ttf");
    titleFont.loadFromFile("assets/font/PixeloidSans-Bold.ttf");

    title.setFont(titleFont);
    title.setString("Fallen Champion");
    title.setCharacterSize(150);
    title.setFillColor(sf::Color::White);
    title.setPosition(300, 400);

    startButton.setFont(font);
    startButton.setString("Start Game");
    startButton.setCharacterSize(50);
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition(300, 800);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(50);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(300, 900);
}

void StartScreen::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(game->getWindow());
        isStartButtonHovered = startButton.getGlobalBounds().contains(mousePos.x, mousePos.y);
        isExitButtonHovered = exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (isStartButtonHovered) {
            game->startGame();
        } else if (isExitButtonHovered) {
            game->getWindow().close();
        }
    }
}

void StartScreen::Update(float deltaTime) {
    startButton.setFillColor(isStartButtonHovered ? sf::Color::Yellow : sf::Color::White);
    exitButton.setFillColor(isExitButtonHovered ? sf::Color::Yellow : sf::Color::White);
}

void StartScreen::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    window.draw(title);
    window.draw(startButton);
    window.draw(exitButton);
}