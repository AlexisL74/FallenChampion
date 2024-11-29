#include "FallenChampion.h"
#include <iostream>

FallenChampion* FallenChampion::instance = nullptr;

FallenChampion* FallenChampion::getInstance() {
    if (instance == nullptr) {
        instance = new FallenChampion();
    }
    return instance;
}

FallenChampion::FallenChampion() : interface(this) {
    instance = this;
    init_window("Fallen Champion", WIDTH, HEIGHT);
    view.setSize(WIDTH / 2, HEIGHT / 2);
    // level = new Level(sf::FloatRect(0.0f, 0.0f, 500.0f, 500.0f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2.0f, 2.0f), this);
    startScreen = new StartScreen(this);
}

void FallenChampion::init_window(const std::string windowName, const int windowWidth, const int windowHeight) {
    window.create(sf::VideoMode(windowWidth, windowHeight), windowName);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
}

void FallenChampion::startGame() {
    isGameStarted = true;
    isGameOver = false;
    level = new Level(sf::FloatRect(0.0f, 0.0f, 500.0f, 500.0f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(2.0f, 2.0f));
}

void FallenChampion::gameOver() {
    gameOverScreen = new GameOver();
    isGameOver = true;
    isGameStarted = false;
}

void FallenChampion::run() {
    sf::Clock Clock;
    while (window.isOpen()) {
        // std::cout<<view.getCenter().x << " " << view.getCenter().y<<std::endl;
        float deltaTime = Clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (!isGameStarted && !isGameOver) {
                startScreen->handleEvent(event);
            } else if (isGameOver) {
                gameOverScreen->handleEvent(event);
            }
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                break;
                case sf::Event::LostFocus:
                    hasfocus = false;
                break;
                case sf::Event::GainedFocus:
                    hasfocus = true;
                break;
            }
        }
        if (isGameStarted) {
            level->Update(deltaTime);
            interface.Update(deltaTime);
        } else if (isGameOver) {
            gameOverScreen->Update(deltaTime);
        } else {
            startScreen->Update(deltaTime);
        }

        window.clear();
        if (isGameStarted) {
            level->draw(window);
            interface.draw(window);
        } else if (isGameOver) {
            gameOverScreen->draw(window);
        } else {
            startScreen->draw(window);
        }
        window.display();
    }
}