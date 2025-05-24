#include "Level2.h"

Level2::Level2() {
    this->player = Player(50.f, 50.f);

    box.setSize({ 100.f, 100.f });
    box.setFillColor(sf::Color::Blue);
    box.setPosition(200.f, 200.f);
}

void Level2::update(sf::RenderTarget* target, float deltaTime) {
    player.update(target, deltaTime);
}

void Level2::render(sf::RenderTarget& target) {
    player.render(target);
    target.draw(box);
}

void Level2::reset() {
    resetPlayer();
    box.setPosition(200.f, 200.f);
}

void Level2::resetPlayer() {
    player.getShape().setPosition(50.f, 50.f);
}

void Level2::resetEnemies()
{
   
}