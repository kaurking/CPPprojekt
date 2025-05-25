#include "Level1.h"

Level1::Level1() : Level(25.f, 25.f) {
    
    enemies.push_back(Enemy({ {100.f, 100.f}, {380.f, 100.f}, {380.f, 280.f}, {100.f, 280.f}, {100.f, 100.f} }, 475.f));
    enemies.push_back(Enemy({ {420.f, 100.f}, {700.f, 100.f}, {700.f, 280.f}, {420.f, 280.f}, {420.f, 100.f} }, 475.f));
    enemies.push_back(Enemy({ {100.f, 320.f}, {380.f, 320.f}, {380.f, 500.f}, {100.f, 500.f}, {100.f, 320.f} }, 475.f));
    enemies.push_back(Enemy({ {420.f, 320.f}, {700.f, 320.f}, {700.f, 500.f}, {420.f, 500.f}, {420.f, 320.f} }, 475.f));
    enemies.push_back(Enemy({ {100.f, 50.f}, {700.f, 50.f} }, 600.f));
    enemies.push_back(Enemy({ {700.f, 550.f}, {100.f, 550.f} }, 600.f));
    enemies.push_back(Enemy({ {750.f, 550.f}, {750.f, 50.f} }, 500.f));
    enemies.push_back(Enemy({ {50.f, 50.f}, { 50.f, 550.f } }, 500.f));
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
