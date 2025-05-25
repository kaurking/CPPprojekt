#include "Level2.h"
#include <iostream>
#include <filesystem>

Level2::Level2() : Level(20.f, 20.f) 
{
    finish.setPosition(750.f, 550.f);
    Level::initBoxes("Level2.txt");
}

void Level2::update(const sf::RenderTarget* target, float deltaTime) 
{
    Level::update(target, deltaTime); // m�ngija ja vastaste collisioni jms jaoks
}

void Level2::render(sf::RenderTarget& target) 
{
    Level::render(target); // m�ngija, vastaste, seinade jms renderimine  
}

void Level2::reset() 
{
    player.reset();
    Level::initBoxes("Level2.txt");
}

void Level2::resetEnemies()
{
   
}