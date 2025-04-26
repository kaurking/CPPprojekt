#pragma once

#include<iostream>
#include<vector>

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
	bool levelSelect;

	// Hiire positsioon
	sf::Vector2i hiireKoordidAknas;


	// Mängu loogika

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
	void updateMousePositions();
	void update();

	void render();
};

