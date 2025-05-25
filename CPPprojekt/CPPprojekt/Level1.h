#pragma once

#include "Level.h"

class Level1 : public Level 
{
private: 
	// mis levelis sees on

public: 
    Level1();

    void update(const sf::RenderTarget* target, float deltaTime) override;
    void render(sf::RenderTarget& target) override;
    void reset() override;
    
};
