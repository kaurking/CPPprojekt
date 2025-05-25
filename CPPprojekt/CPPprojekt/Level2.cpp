#include "Level2.h"

Level2::Level2() : Level(50.f, 50.f) {

    box.setSize({ 100.f, 100.f });
    box.setFillColor(sf::Color::Blue);
    box.setPosition(200.f, 200.f);
    walls.push_back(box);
}

void Level2::update(const sf::RenderTarget* target, float deltaTime) {
    Level::update(target, deltaTime); // m�ngija ja vastaste collisioni jaoks


}

void Level2::render(sf::RenderTarget& target) {
    Level::render(target); // m�ngija ja vastaste renderimine
    target.draw(box);
}

void Level2::reset() {
    player.reset();
    box.setPosition(200.f, 200.f);
}

void Level2::resetEnemies()
{
   
}