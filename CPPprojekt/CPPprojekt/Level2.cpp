#include "Level2.h"

Level2::Level2() : Level(10.f, 300.f) {
    sf::RectangleShape sein1;
    sein1.setFillColor(sf::Color::Blue);
    sein1.setSize({ 50.f, 275.f });
    sein1.setPosition(100.f, 0.f);
    walls.push_back(sein1);

    sf::RectangleShape sein2;
    sein2.setFillColor(sf::Color::Blue);
    sein2.setSize({ 50.f, 275.f });
    sein2.setPosition(100.f, 325.f);
    walls.push_back(sein2);


    sf::RectangleShape secretBox;
    secretBox.setFillColor(sf::Color::Blue);
    secretBox.setSize({ 50.f, 50.f });
    secretBox.setPosition(100.f, 275.f);
    movableBoxes.push_back(secretBox);
}

void Level2::update(const sf::RenderTarget* target, float deltaTime) {
    Level::update(target, deltaTime); // m�ngija ja vastaste collisioni jaoks
}

void Level2::render(sf::RenderTarget& target) {
    Level::render(target); // m�ngija, vastaste, seinade ja kastide renderimine  
}

void Level2::reset() {
    player.reset();
    box.setPosition(200.f, 200.f);
    box2.setPosition(50.f, 50.f);
}

void Level2::resetEnemies()
{
   
}