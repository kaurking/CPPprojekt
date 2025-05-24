#include "Level3.h"

Level3::Level3() {
    this->player = Player(50.f, 50.f);

    box.setSize({ 100.f, 100.f });
    box.setFillColor(sf::Color::Red);
    box.setPosition(200.f, 200.f);
}

void Level3::update(sf::RenderTarget* target, float deltaTime) {
    player.update(target, deltaTime);
}

void Level3::render(sf::RenderTarget& target) {
    player.render(target);
    target.draw(box);
}

void Level3::reset() {
    player.setPositionOfPlayer(50.f, 50.f);
    box.setPosition(200.f, 200.f);
}