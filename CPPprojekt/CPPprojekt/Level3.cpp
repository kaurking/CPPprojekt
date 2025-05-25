#include "Level3.h"

Level3::Level3() : Level(50.f, 50.f) {

    box.setSize({ 100.f, 100.f });
    box.setFillColor(sf::Color::Red);
    box.setPosition(200.f, 200.f);
}

void Level3::update(const sf::RenderTarget* target, float deltaTime) {
    Level::update(target, deltaTime); // m�ngija ja vastaste collisioni jaoks

}

void Level3::render(sf::RenderTarget& target) {
    Level::render(target); // m�ngija ja vastaste renderimine
    target.draw(box);
}

void Level3::reset() {
    player.reset();
    box.setPosition(200.f, 200.f);
}

void Level3::resetEnemies()
{

}