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
        float x = 200.f;
        float y = 200.f + i * 50;
        std::vector<sf::Vector2f> path;
        path.push_back({ x, y });
        path.push_back({ x + 380, y });

        Enemy e1(path, speed);
        enemies.push_back(e1);

        x = 580.f;
        y = 225.f + i * 50;
        std::vector<sf::Vector2f> path;
        path.push_back({ x, y });
        path.push_back({ x - 380, y });

        Enemy e2(path, speed);
        enemies.push_back(e2);
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
    player.reset();
    Level::initBoxes("Level3.txt");
}

void Level3::resetEnemies()
{

}