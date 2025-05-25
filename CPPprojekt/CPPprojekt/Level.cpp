#include "Level.h"
#include <iostream>
#include "CollisionUtils.h"

Level::Level(float spawnX, float spawnY) : player(spawnX, spawnY) {}

void Level::update(const sf::RenderTarget* target, float deltaTime)
{
    sf::Vector2f PrevPlayerPos = player.getShape().getPosition();
    player.update(target, deltaTime);
    updateEnemies(target, deltaTime);
    checkPlayerEnemyCollision();
    checkPlayerWallCollision(PrevPlayerPos);
}

void Level::updateEnemies(const sf::RenderTarget* target, float deltaTime)
{
    for (auto& enemy : enemies)
        enemy.update(target, deltaTime);
}

void Level::checkPlayerWallCollision(const sf::Vector2f prevPlayerPos)
{
    for (auto& wall : walls)
    {
        if (checkRectangleCollision(player.getShape(), wall)) 
        {
            player.setPositionOfPlayer(prevPlayerPos.x, prevPlayerPos.y);
            break;
        }
    }
}

void Level::checkPlayerEnemyCollision()
{
    for (auto& enemy : enemies)
    {
        if (checkCircleCollision(player.getShape(), enemy.getShape()))
        {
            player.reset(); // mingi m�rguande peaks ka andma
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