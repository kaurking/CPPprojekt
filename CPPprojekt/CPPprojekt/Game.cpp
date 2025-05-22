#include "Game.h"


// Konstruktor / Destruktor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->levelSelectScreen.initButtons(this->window);
}

Game::~Game()
{
	delete this->window;
}

// Konstruktor abi
void Game::initVariables()
{
	this->window = nullptr;
	this->currentState = GameState::LevelSelect;
	this->player = Player(50.f, 50.f);
	this->levelSelectScreen = LevelSelectScreen();
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
			this->handleKeyPress(this->ev.key.code);
			break;

		case sf::Event::MouseButtonPressed:
			this->handleMouseClick(this->ev.mouseButton);
			break;

		default: 
			break;
		}
	}
}

// mõeldud mängu ajal sellega seonduvate nupuvajutuste jaoks
void Game::handleKeyPress(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Escape)
	{
		if (this->currentState == GameState::LevelSelect)
			this->currentState = GameState::Playing;
		else if (this->currentState == GameState::Playing)
			this->currentState = GameState::LevelSelect;

		return;
	}

	if (this->currentState == GameState::Playing)
	{
		// mängu ajal midagi
	}
	else if (this->currentState == GameState::LevelSelect)
	{
		// menüünpud
	}
}

// mõeldud mängu ajal sellega seonduvate hiireklahvivajutuste jaoks
void Game::handleMouseClick(const sf::Event::MouseButtonEvent& mouse)
{
	if (this->currentState == GameState::LevelSelect && mouse.button == sf::Mouse::Left)
	{
		sf::Vector2i mp = sf::Mouse::getPosition(*this->window);
		int lvl = this->levelSelectScreen.wasButtonClicked(&mp);

		switch (lvl)
		{
		case 0: std::cout << "Level 0\n"; break;
		case 1: std::cout << "Level 1\n"; break;
		case 2: std::cout << "Level 2\n"; break;
		case 3: std::cout << "Level 3\n"; break;
		default: throw("WHaT!HOW?");
		}

		this->currentState = GameState::Playing;
	}
}


void Game::update(float deltaTime)
{
	this->pollEvents();

	if (this->currentState == GameState::Playing)
	{
		this->player.update(this->window, deltaTime);
	}
	else if (this->currentState == GameState::LevelSelect)
	{
		// level select screen?
	}
}


void Game::render()
{
	this->window->clear();

	switch (this->currentState)
	{
	case GameState::Playing:
		this->player.render(*this->window);
		break;

	case GameState::LevelSelect:
		this->levelSelectScreen.render(*this->window);
		break;
	case GameState::Paused:
		// pausiekraan
		break;
	}

	this->window->display();
}
