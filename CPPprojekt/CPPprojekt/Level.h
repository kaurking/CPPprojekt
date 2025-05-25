#pragma once

#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

#include <string>

class Level 
{
protected:
	Player player;
	Level(float spawnX = 0.f, float spawnY = 0.f);
	sf::RectangleShape finish;
	bool isDone = false;

	//Objektid levelis
	
	// vektor, kus Enemy-d elavad
	std::vector<Enemy> enemies;

	virtual void resetEnemies();
	
	// vector, kuhu pystitati seinad
	std::vector<sf::RectangleShape> walls;
	// vector, kuhu lykati kastid
	std::vector<sf::RectangleShape> movableBoxes;
	// vektor, kus saab läbi kõndida
	std::vector<sf::RectangleShape> backgroundBoxes;
	
	// loeb failist seinad, liigutatavad kastid ja tausta
	void initBoxes(std::string filePath);



	void updateEnemies(const sf::RenderTarget* target, float deltaTime);

	// kontrolli, kas m�ngija l�ks vastasele pihta
	void checkPlayerEnemyCollision();
	// kontorllib, kas mangija pyyab labi seina minna
	void checkPlayerWallCollision(const sf::Vector2f prevPlayerPos);
	void movePlayerWithBox(const sf::Vector2f prevPlayerPos, const sf::RenderTarget* target);
public:
	bool getIsDone();
	void setIsDone(bool uus);
	virtual void setFinish(sf::RectangleShape& fin);
	virtual void update(const sf::RenderTarget* target, float deltaTime);
	virtual void render(sf::RenderTarget& target);
	virtual void reset();

	virtual ~Level() = default;

};