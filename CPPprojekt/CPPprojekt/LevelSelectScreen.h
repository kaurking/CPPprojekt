#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Button.h"

class LevelSelectScreen
{
private:
	sf::Font font;
	std::vector<Button> buttons;
	sf::Vector2f buttonSize;
	float buttonSpacing;


	void initVariables();
	
public:
	LevelSelectScreen();

	int wasButtonClicked(sf::Vector2i* mousePos);
	void initButtons(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget& arget);
};

