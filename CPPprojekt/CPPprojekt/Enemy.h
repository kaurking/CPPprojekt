#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Enemy 
{
private:
	sf::CircleShape shape;
	float movementSpeed;

	// kui tahta panna vastast 2 punkti vahel liikuma sirgelt, siis need vaja
	sf::Vector2f startPos;
	sf::Vector2f endPos;

	// vektor, mis defineeriv vaenlase liikumise teekonna. �he sf::vector2f'ga vektor teeb nii, et 
	// startPos = endPos. Kui on 2 sf::vector2f'i vektoris, siis on m�eldud sirgjooneliseks 
	// liikumiseks ja kui rohkem, siis saab vektori abil m��rata neid punkte. 
	std::vector<sf::Vector2f> pathOfEnemy;

	// liikumise jaoks
	unsigned int currentTargetIndex = 1;
	bool movingForward = true;

	void initShape();
public: 
	Enemy(std::vector<sf::Vector2f> pathOfEnemy = { {0.f, 0.f} }, float moveSpeed = 200.f);
	~Enemy();

	sf::CircleShape getShape();
	sf::Vector2f getStartPos();
	void move(float deltaTime);
	void update(const sf::RenderTarget* target, float deltaTime);
	void render(sf::RenderTarget& target);
	void reset();

};
