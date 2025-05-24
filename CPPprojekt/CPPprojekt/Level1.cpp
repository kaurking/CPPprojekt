#include "Level1.h"

Level1::Level1() {
    this->player = Player(50.f, 50.f);

    box.setSize({ 100.f, 100.f });
    box.setFillColor(sf::Color::Green);
    box.setPosition(200.f, 200.f);
}

void Level1::update(sf::RenderTarget* target, float deltaTime) {
    player.update(target ,deltaTime);
}

void Level1::render(sf::RenderTarget& target) {
    player.render(target);
    target.draw(box);
}

void Level1::reset() {
    player.setPositionOfPlayer(50.f, 50.f);
    box.setPosition(200.f, 200.f);
}