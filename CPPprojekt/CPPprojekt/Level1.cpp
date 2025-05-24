#include "Level1.h"

Level1::Level1() {
    this->player = Player(50.f, 50.f);

    this->enemy1 = Enemy({ {100.f, 100.f}, {300.f, 100.f}, {300.f, 300.f}, {100.f, 300.f} });

}

void Level1::update(sf::RenderTarget* target, float deltaTime) {
    player.update(target ,deltaTime);
    enemy1.update(target, deltaTime);
}

void Level1::render(sf::RenderTarget& target) {
    player.render(target);
    enemy1.render(target);
}

void Level1::reset() {
    resetPlayer();
    resetEnemies();
}

void Level1::resetPlayer() {
    player.getShape().setPosition(50.f, 50.f);
}

void Level1::resetEnemies()
{
    enemy1.reset();
}