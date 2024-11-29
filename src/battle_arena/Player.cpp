#include "Player.h"

#include <iostream>

#include "../FallenChampion.h"
#include "../engine/Utils.h"
#include "weapon/BaseSword.h"
#include "weapon/RedMagicStaff.h"

Player::Player(const sf::Vector2f pos, sf::Vector2f size) : Entity(pos, size) {
    this->game = FallenChampion::getInstance();
    this->scale = size;
    this->maxHealth = 100.0f;
    this->health = maxHealth;
    this->moveSpeed = 250.0f;
    textureInfo = game->getTexture("Player");
    body.setPosition(pos);
    Player::onLoad();
}

void Player::onLoad() {
    weapon = new RedMagicStaff(getPosition(), sf::Vector2f(1.25f, 1.25f), this);
    Entity::onLoad();
}

void Player::Update(const float deltaTime) {
    if(game->getHasFocus()) {
        sf::Vector2f playerMovementInput = engine::Utils::normalize(getMovementInput());
        if(playerMovementInput != sf::Vector2f(0.0f, 0.0f)) {
            applyMovement(playerMovementInput, deltaTime);

            // Flip the sprite
            if (playerMovementInput.x > 0) {
                sprite.setScale(scale.x, scale.y);
            } else if (playerMovementInput.x < 0) {
                sprite.setScale(-scale.x, scale.y);
            }
        }

        // Update animation depending on movement
        if(playerMovementInput != sf::Vector2f(0.0f, 0.0f) && !isMoving) {
            isMoving = true;
            sprite.setAnimation("run");
        } else if(playerMovementInput == sf::Vector2f(0.0f, 0.0f) && isMoving) {
            isMoving = false;
            sprite.setAnimation("idle");
        }

        weapon->Update(deltaTime);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && !isRMbtnPressed) {
            weapon->attack();
            isRMbtnPressed = true;
        } else if (!sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            isRMbtnPressed = false;
        }
    }

    Entity::Update(deltaTime);
}

void Player::draw(sf::RenderWindow &window) {
    weapon->draw(window);
    Entity::draw(window);
}

void Player::onDeath() {
    // Un fix temporaire tant que le gaemo n'est pas fini
    //game->startGame();
    game->gameOver();
}

sf::Vector2f Player::getMovementInput() {
    sf::Vector2f movement = sf::Vector2f(0.0f, 0.0f);
    using keyboard = sf::Keyboard;

    if(keyboard::isKeyPressed(keyboard::Up) || keyboard::isKeyPressed(keyboard::Z)) {
        movement.y = -1.0f;
    } else if(keyboard::isKeyPressed(keyboard::Down) || keyboard::isKeyPressed(keyboard::S)) {
        movement.y = 1.0f;
    }

    if(keyboard::isKeyPressed(keyboard::Right) || keyboard::isKeyPressed(keyboard::D)) {
        movement.x = 1.0f;
    } else if(keyboard::isKeyPressed(keyboard::Left) || keyboard::isKeyPressed(keyboard::Q)) {
        movement.x = -1.0f;
    }

    return movement;
}
