#include "Level1.h"

Level1::Level1() : Level(50.f, 50.f) {
    
    enemies.push_back(Enemy({ {100.f, 100.f}, {300.f, 100.f}, {300.f, 300.f}, {100.f, 300.f} }));
}

void Level1::update(const sf::RenderTarget* target, float deltaTime) {
    Level::update(target, deltaTime); // m�ngija ja vastaste collisioni jaoks

}

void Level1::render(sf::RenderTarget& target) {
    Level::render(target); // m�ngija ja vastaste renderimine

}

void Level1::reset() {
    Level::reset();
}
