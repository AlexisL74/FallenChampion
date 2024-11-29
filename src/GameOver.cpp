#include "GameOver.h"

#include "FallenChampion.h"

GameOver::GameOver() : game(FallenChampion::getInstance()), isStartButtonHovered(false), isExitButtonHovered(false) {
    if (!backgroundTexture.loadFromFile("assets/gameover_background.png")) {
        std::cerr << "Failed to gameover screen background texture" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setColor(sf::Color(100, 100, 100, 255));
    backgroundSprite.setOrigin(backgroundSprite.getLocalBounds().width / 2, backgroundSprite.getLocalBounds().height / 2);
    backgroundSprite.setScale(game->getView().getSize().x / backgroundSprite.getLocalBounds().width, game->getView().getSize().y / backgroundSprite.getLocalBounds().height);
    backgroundSprite.setPosition(game->getView().getCenter());

    game->getView().setCenter(500, 500);

    font.loadFromFile("assets/font/PixeloidSans.ttf");
    titleFont.loadFromFile("assets/font/PixeloidSans-Bold.ttf");

    title.setFont(titleFont);
    title.setString("Game Over");
    title.setCharacterSize(150/2);
    title.setFillColor(sf::Color::Red);
    title.setPosition(game->getView().getSize().x / 2 - title.getLocalBounds().width / 2, 100);

    startButton.setFont(font);
    startButton.setString("Restart Game");
    startButton.setCharacterSize(50/2);
    startButton.setFillColor(sf::Color::White);
    startButton.setPosition(game->getView().getSize().x / 2 - startButton.getLocalBounds().width / 2, 300);

    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(50/2);
    exitButton.setFillColor(sf::Color::White);
    exitButton.setPosition(game->getView().getSize().x / 2 - exitButton.getLocalBounds().width / 2, 400);
}

void GameOver::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(game->getWindow());
        sf::Vector2f worldPos = game->getWindow().mapPixelToCoords(mousePos);
        isStartButtonHovered = startButton.getGlobalBounds().contains(worldPos.x, worldPos.y);
        isExitButtonHovered = exitButton.getGlobalBounds().contains(worldPos.x, worldPos.y);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (isStartButtonHovered) {
            game->startGame();
        } else if (isExitButtonHovered) {
            game->getWindow().close();
        }
    }
}

void GameOver::Update(float deltaTime) {
    title.setPosition((game->getView().getCenter().x - game->getView().getSize().x / 2)+150 ,  (game->getView().getCenter().y - game->getView().getSize().y / 2) + 150);
    startButton.setPosition((game->getView().getCenter().x - game->getView().getSize().x / 2)+150, (game->getView().getCenter().y - game->getView().getSize().y / 2) + 325);
    exitButton.setPosition((game->getView().getCenter().x - game->getView().getSize().x / 2)+150, (game->getView().getCenter().y - game->getView().getSize().y / 2) + 425);

    startButton.setFillColor(isStartButtonHovered ? sf::Color::Yellow : sf::Color::White);
    exitButton.setFillColor(isExitButtonHovered ? sf::Color::Yellow : sf::Color::White);
}

void GameOver::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
    window.draw(title);
    window.draw(startButton);
    window.draw(exitButton);
}