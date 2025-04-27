#include "Game.h"


// Konstruktor / Destruktor
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// Konstruktor abi
void Game::initVariables()
{
	this->window = nullptr;
	levelSelect = false;
	this->player = Player(50.f, 50.f);
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(165);
}


// Funktsioonid

const bool Game::isRunning()
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()
{
	this->hiireKoordidAknas = sf::Mouse::getPosition(*this->window);
}


void Game::update()
{
	if (this->levelSelect) 
	{
		this->pollEvents();
		this->updateMousePositions();
	}
	else 
	{
		this->pollEvents();
		this->player.update();
		this->updateMousePositions();
	}
}

void Game::render()
{
	this->window->clear();

	if (this->levelSelect)
	{
		// Level select screen siia
	}
	else
	{
		// Kui on levelis
		this->player.render(this->window);
	}
	

	

	this->window->display();
}
