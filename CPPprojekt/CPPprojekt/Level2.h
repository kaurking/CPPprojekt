#pragma once

#include "Level.h"
#include "CollisionUtils.h"

class Level2 : public Level
{
private:
    // mis levelis sees on
    sf::RectangleShape box;
public:
    Level2();

    void update(const sf::RenderTarget* target, float deltaTime) override;
    void render(sf::RenderTarget& target) override;
    void reset() override;
    void resetEnemies();

};
