#pragma once

#include "Level.h"

class Level3 : public Level
{
private:
    // mis levelis sees on
public:
    Level3();

    void initEnemies();
    void update(const sf::RenderTarget* target, float deltaTime) override;
    void render(sf::RenderTarget& target) override;
    void reset() override;
    void resetEnemies();

};
