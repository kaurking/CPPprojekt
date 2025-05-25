#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>

class movableBox
{
private:
	sf::RectangleShape shape;



public:
	movableBox(sf::Vector2f position, sf::Vector2f size);

	bool tryMove(std::string direction);

	void update();
	void render(sf::RenderTarget& target);
};