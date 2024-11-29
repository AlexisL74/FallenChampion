#include "HUD.h"

#include "../FallenChampion.h"

HUD::HUD() : game(FallenChampion::getInstance()) {
    onLoad();
}

void HUD::onLoad() {
    if (!font.loadFromFile("assets/font/PixeloidSans.ttf")) {
        std::cerr << "Cannot open font!" << std::endl;
        return;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(15);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("Score: 0000000");

    engine::TextureInfo* heartTexture = game->getTexture("Heart");
    for (int i = 0; i < 10; ++i) {
        engine::AnimatedSprite heartSprite;
        heartSprite.addAnimation("full", heartTexture->texture, heartTexture->frameSize.x, heartTexture->frameSize.y, heartTexture->frameCount.x, 0.0f, 0);
        heartSprite.addAnimation("mid", heartTexture->texture, heartTexture->frameSize.x, heartTexture->frameSize.y, heartTexture->frameCount.x, 0.0f, 1);
        heartSprite.addAnimation("empty", heartTexture->texture, heartTexture->frameSize.x, heartTexture->frameSize.y, heartTexture->frameCount.x, 0.0f, 2);
        heartSprite.setAnimation("full");
        heartSprite.setScale(1.5f, 1.5f);
        heartSprite.setPosition(sf::Vector2f((float)(i * 20), 0.0f));
        hearts.push_back(heartSprite);
    }
}

void HUD::Update(const float deltaTime) {
    snprintf(scoreInfo, sizeof(scoreInfo), "Score: %7u", game->getScore());
    scoreText.setString(scoreInfo);

    sf::Vector2f viewCenter = game->getView().getCenter();
    sf::Vector2f viewSize = game->getView().getSize();

    scoreText.setPosition(viewCenter.x + viewSize.x / 2 - 120, viewCenter.y - viewSize.y / 2 + 10);

    engine::TextureInfo* heartTexture = game->getTexture("Heart");
    for (size_t i = 0; i < hearts.size(); ++i) {
        if (game->getPlayer()->getHealth() > (i * 10) + 5) {
            hearts[i].setAnimation("full");
        } else if (game->getPlayer()->getHealth() > i * 10) {
            hearts[i].setAnimation("mid");
        } else {
            hearts[i].setAnimation("empty");
        }
        sf::Vector2f heartPos = sf::Vector2f((viewCenter.x - viewSize.x / 2 + 20) + (i * 22), (viewCenter.y - viewSize.y / 2 + 20));
        hearts[i].setPosition(heartPos);
    }
}

void HUD::draw(sf::RenderWindow &window) {
    window.draw(scoreText);
    for (const auto& heart : hearts) {
        window.draw(heart);
    }
}