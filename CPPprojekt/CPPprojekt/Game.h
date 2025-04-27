#pragma once

#include<iostream>
#include<vector>
#include "Player.h"
#include "LevelSelectScreen.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Game
{
private:

	// Isendimuutujad
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	// Mängu loogika
	LevelSelectScreen levelSelectScreen;
	bool levelSelect;

	// Mängu objektid
	Player player;

	// Privaatsed funktsioonid
	void initVariables();	//init = initialize
	void initWindow();

public:

	// Konstruktor / Destruktor
	Game();
	virtual ~Game();

	// Funktsioonid
	const bool isRunning();

	void pollEvents();
	void update();

	void render();
};

