#pragma once

#include <SFML/Graphics.hpp>

class Level 
{
private:

public:
	virtual void update(sf::RenderTarget* target, float deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;
	virtual void reset() = 0;

	virtual ~Level() = default;

};