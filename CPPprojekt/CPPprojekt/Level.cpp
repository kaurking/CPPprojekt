#include "Level.h"
#include <iostream>
#include "CollisionUtils.h"
#include <fstream>
#include <sstream>

Level::Level(float spawnX, float spawnY) : player(spawnX, spawnY) {}

bool Level::getIsDone()
{
    return isDone;
}

void Level::setIsDone(bool uus)
{
    isDone = uus;
}

void Level::setFinish(sf::RectangleShape& fin)
{
    finish = fin;
}

void Level::update(const sf::RenderTarget* target, float deltaTime)
{
    sf::Vector2f PrevPlayerPos = player.getShape().getPosition();
    player.update(target, deltaTime);
    updateEnemies(target, deltaTime);
    checkPlayerEnemyCollision();
    checkPlayerWallCollision(PrevPlayerPos);
    movePlayerWithBox(PrevPlayerPos, target);
    if (checkCircleRectangleCollision(player.getShape(), finish))
    {
        setIsDone(true);
    }
}

// loeb failist kõik kastid, mis levelis on ja populeerib vastavad vektorid
void Level::initBoxes(std::string filePath)
{
    walls.clear();
    movableBoxes.clear();
    backgroundBoxes.clear();

    std::ifstream fin(filePath);
    if (!fin) std::cerr << "Failed to load from file: " << filePath << '\n';

    std::string rida;
    std::vector<sf::RectangleShape>* target = &walls;
    while (getline(fin, rida))
    {
        if (rida.rfind("//", 0) == 0)
        {
            continue;
        }
        if (rida == "boxes") 
        {
            target = &movableBoxes; 
            continue;
        }
        if (rida == "background")
        {
            target = &backgroundBoxes;
            continue;
        }

        // failist rect info
        std::stringstream ss(rida);
        std::string xStr, yStr, sizeXStr, sizeYStr, rStr, gStr, bStr;
        
        std::getline(ss, xStr, ';');
        std::getline(ss, yStr, ';');
        std::getline(ss, sizeXStr, ';');
        std::getline(ss, sizeYStr, ';');
        std::getline(ss, rStr, ';');
        std::getline(ss, gStr, ';');
        ss >> bStr;

        // string to float
        float x = std::stof(xStr) * 25;
        float y = std::stof(yStr) * 25;
        float sizeX = std::stof(sizeXStr) * 25;
        float sizeY = std::stof(sizeYStr) * 25;
        int r = std::stoi(rStr);
        int g = std::stoi(gStr);
        int b = std::stoi(bStr);

        sf::RectangleShape box;
        box.setPosition(x, y);
        box.setSize({ sizeX, sizeY });
        box.setFillColor(sf::Color(r, g, b));

        target->push_back(box);
    }

    finish.setSize({ 50.f, 50.f });
    finish.setFillColor(sf::Color::Green);
}

void Level::updateEnemies(const sf::RenderTarget* target, float deltaTime)
{
    for (auto& enemy : enemies)
        enemy.update(target, deltaTime);
}

void Level::resetEnemies()
{
    for (auto& enemy : this->enemies)
    {
        enemy.reset();
    }
}

void Level::reset()
{
    this->player.reset();
    this->resetEnemies();
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
            sf::Vector2f size = box.getSize();
            bool insideWindow =
                newBoxPos.x >= 0 &&
                newBoxPos.y >= 0 &&
                newBoxPos.x + size.x <= windowBounds.width &&
                newBoxPos.y + size.y <= windowBounds.height;            

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
        if (checkCircleCircleCollision(player.getShape(), enemy.getShape()))
        {
            player.reset(); // mingi m�rguande peaks ka andma
            break;
        }
    }
}

void Level::render(sf::RenderTarget& target)
{
    for (auto& bg : backgroundBoxes)
        target.draw(bg);
    target.draw(finish);
    player.render(target);
    for (auto& enemy : enemies)
        enemy.render(target);
    for (auto& wall : walls)
        target.draw(wall);
    for (auto& box : movableBoxes)
        target.draw(box);
    
}