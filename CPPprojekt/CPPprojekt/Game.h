#pragma once

#include<iostream>
#include<vector>
#include "Player.h"
#include "LevelSelectScreen.h"
#include "PausedScreen.h"
#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

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

	// mängu praegune seis
	enum class GameState { Playing, LevelSelect, Paused };
	GameState currentState;

	// mängu levelid
	Level* currentLevel;
	std::vector<Level*> levels;

	// Mängu loogika
	LevelSelectScreen levelSelectScreen;
	PausedScreen pausedScreen;

	// Mängu objektid

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
	void handleKeyPress(sf::Keyboard::Key key);
	void handleMouseClick(const sf::Event::MouseButtonEvent& mouse);
	void update(float deltaTime);

	void render();
};

