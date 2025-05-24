#include "Level1.h"

Level1::Level1() : Level(50.f, 50.f) {
    
    this->enemy1 = Enemy({ {100.f, 100.f}, {300.f, 100.f}, {300.f, 300.f}, {100.f, 300.f} });
    enemies.push_back(enemy1);
}

void Level1::update(const sf::RenderTarget* target, float deltaTime) {
    Level::update(target, deltaTime); // mängija ja vastaste collisioni jaoks

}

void Level1::render(sf::RenderTarget& target) {
    Level::render(target); // mängija ja vastaste renderimine

}

void Level1::reset() {
    player.reset();
    resetEnemies();
}

void Level1::resetEnemies()
{
    enemy1.reset();
}