#include "Level3.h"
#include <iostream>
#include <filesystem>

Level3::Level3() : Level(140.f, 440.f)
{
    finish.setPosition(625.f, 125.f);
    Level::initBoxes("Level3.txt");
    initEnemies();
}

void Level3::initEnemies()
{
    float speed = 250.f;
    for (int i = 0; i < 4; ++i)
    {
        enemies.push_back(Enemy({ {200.f, 200.f + i * 50}, {200.f + 380, 200.f + i * 50} }, speed));
        enemies.push_back(Enemy({ {580.f, 225.f + i * 50}, {580.f - 380, 225.f + i * 50} }, speed));
    }
}

void Level3::update(const sf::RenderTarget* target, float deltaTime)
{
    Level::update(target, deltaTime); // m ngija ja vastaste collisioni jms jaoks
}

void Level3::render(sf::RenderTarget& target)
{
    Level::render(target); // m ngija, vastaste, seinade jms renderimine  
}

void Level3::reset()
{
    Level::reset();
    Level::initBoxes("Level3.txt");
}

void Level3::resetEnemies()
{

}