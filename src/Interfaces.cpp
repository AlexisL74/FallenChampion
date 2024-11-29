#include "Interfaces.h"
#include "FallenChampion.h"

void Interfaces::onLoad() {
    if (!font.loadFromFile("assets/font/PixeloidSans.ttf")) {
        std::cerr << "Cannot open font!" << std::endl;
        return;
    }

    fpsText.setFont(font);
    fpsText.setCharacterSize(15);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setString("FPS: 0.0, Frame time: 0.00000");
}

void Interfaces::Update(const float deltaTime) {
    fpsGUI(deltaTime);
}

void Interfaces::draw(sf::RenderWindow &window) {
    window.draw(fpsText);
}

void Interfaces::fpsGUI(const float dt) {
    snprintf(frameInfoString, sizeof(frameInfoString), "FPS: %3.1f, Frame time: %1.5f", 1.0f / dt, dt);
    fpsText.setString(frameInfoString);
    fpsText.setPosition(ba->getView().getCenter().x + ba->getView().getSize().x / 2 - 260,
                        ba->getView().getCenter().y + ba->getView().getSize().y / 2 - 30);
}
