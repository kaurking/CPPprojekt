#pragma once

#include "Level.h"
#include "player.h"

class Level1 : public Level 
{
private: 
	// mis levelis sees on
    Player player;
    sf::RectangleShape box;
public: 
    Level1();

    void update(sf::RenderTarget* target, float deltaTime) override;
    void render(sf::RenderTarget& target) override;
    void reset() override;

};
