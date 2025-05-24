#pragma once

#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Level 
{
protected:
	Player player;
	Level(float spawnX = 0.f, float spawnY = 0.f);
	// vektor, kus Enemy-d elavad
	std::vector<Enemy> enemies;

	void updateEnemies(const sf::RenderTarget* target, float deltaTime);

	// kontrolli, kas mängija läks vastasele pihta
	void checkPlayerEnemyCollision();
public:
	virtual void update(const sf::RenderTarget* target, float deltaTime);
	virtual void render(sf::RenderTarget& target);
	virtual void reset() = 0;

	virtual ~Level() = default;

};