#include "Level.h"
#include <iostream>
#include "CollisionUtils.h"

Level::Level(float spawnX, float spawnY) : player(spawnX, spawnY) {}

void Level::update(const sf::RenderTarget* target, float deltaTime)
{
    player.update(target, deltaTime);
    updateEnemies(target, deltaTime);
    checkPlayerEnemyCollision();
}

void Level::updateEnemies(const sf::RenderTarget* target, float deltaTime)
{
    for (auto& enemy : enemies)
        enemy.update(target, deltaTime);
}

void Level::checkPlayerEnemyCollision()
{
    for (auto& enemy : enemies)
    {
        if (checkCircleCollision(player.getShape(), enemy.getShape()))
        {
            player.reset(); // mingi märguande peaks ka andma
            break;
        }
    }
}

void Level::render(sf::RenderTarget& target)
{
    player.render(target);
    for (auto& enemy : enemies)
        enemy.render(target);
}