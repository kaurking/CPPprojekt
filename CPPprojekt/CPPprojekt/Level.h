#pragma once

#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Level 
{
protected:
	Player player;
	Level(float spawnX = 0.f, float spawnY = 0.f);

	//Objektid levelis
	
	// vektor, kus Enemy-d elavad
	std::vector<Enemy> enemies;
	// vector, kuhu pystitati seinad
	std::vector<sf::RectangleShape> walls;

	void updateEnemies(const sf::RenderTarget* target, float deltaTime);

	// kontrolli, kas m�ngija l�ks vastasele pihta
	void checkPlayerEnemyCollision();
	void checkPlayerWallCollision(const sf::Vector2f prevPlayerPos);
public:
	virtual void update(const sf::RenderTarget* target, float deltaTime);
	virtual void render(sf::RenderTarget& target);
	virtual void reset() = 0;

	virtual ~Level() = default;

};