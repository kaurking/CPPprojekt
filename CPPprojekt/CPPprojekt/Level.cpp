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
    movePlayerWithBox(PrevPlayerPos, target);
}

void Level::updateEnemies(const sf::RenderTarget* target, float deltaTime)
{
    for (auto& enemy : enemies)
        enemy.update(target, deltaTime);
}

void Level::movePlayerWithBox(const sf::Vector2f prevPlayerPos, const sf::RenderTarget* target)
{
    sf::Vector2f playerMovement = player.getShape().getPosition() - prevPlayerPos;
    for (auto& box : movableBoxes)
    {
        if (checkCircleRectangleCollision(player.getShape(), box))
        {
            sf::Vector2f newBoxPos = box.getPosition() + playerMovement;

            // temp box to test collision
            sf::RectangleShape movedBox = box;
            movedBox.setPosition(newBoxPos);

            // porge seinaga
            bool collidesWithWall = false;
            for (auto& wall : walls) 
            {
                if (checkRectangleRectangleCollision(movedBox, wall)) 
                {
                    collidesWithWall = true;
                    break;
                }
            }

            // porge window bounds-idega
            sf::FloatRect windowBounds(0.f, 0.f, (float)target->getSize().x, (float)target->getSize().y);
            sf::FloatRect boxBounds(newBoxPos, box.getSize());
            bool insideWindow = windowBounds.intersects(boxBounds);

            if (insideWindow && !collidesWithWall)
            {
                box.setPosition(newBoxPos);
            }
            else 
            {
                player.setPositionOfPlayer(prevPlayerPos.x, prevPlayerPos.y);
            }

        }
    }
}

void Level::checkPlayerWallCollision(const sf::Vector2f prevPlayerPos)
{
    for (auto& wall : walls)
    {
        if (checkCircleRectangleCollision(player.getShape(), wall)) 
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
    for (auto& wall : walls)
        target.draw(wall);
    for (auto& box : movableBoxes)
        target.draw(box);
}