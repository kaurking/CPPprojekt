#include "Game.h"


// Konstruktor / Destruktor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->levelSelectScreen.initButtons(this->window);
	this->pausedScreen.initButtons(this->window);
}

Game::~Game()
{
	delete this->window;
}

// Konstruktor abi
void Game::initVariables()
{
	this->window = nullptr;

	// praegune m�ngu state (Playing, LevelSelectScreen v�i Paused)
	this->currentState = GameState::LevelSelect;

	this->levelSelectScreen = LevelSelectScreen();
	this->pausedScreen = PausedScreen();

	// levelid
	this->levels.push_back(new Level1());
	this->levels.push_back(new Level2());
	this->levels.push_back(new Level3());
	// praegune level
	this->currentLevel;
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

// m�eldud m�ngu ajal sellega seonduvate nupuvajutuste jaoks
void Game::handleKeyPress(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Escape)
	{
		if (this->currentState == GameState::Paused)
			this->currentState = GameState::Playing;
		else if (this->currentState == GameState::Playing)
			this->currentState = GameState::Paused;

		return;
	}

	if (this->currentState == GameState::Playing)
	{
		// m�ngu ajal midagi
	}
	else if (this->currentState == GameState::LevelSelect)
	{
		// men��npud
	}
	else if (this->currentState == GameState::Paused)
	{
		// midagi?
	}
}

// m�eldud m�ngu ajal sellega seonduvate hiireklahvivajutuste jaoks
void Game::handleMouseClick(const sf::Event::MouseButtonEvent& mouse)
{
	// kui on levelselect
	if (this->currentState == GameState::LevelSelect && mouse.button == sf::Mouse::Left)
	{
		// lvl on int, kus on number, mitmendat nuppu vajutati
		sf::Vector2i mp = sf::Mouse::getPosition(*this->window);
		int lvl = this->levelSelectScreen.wasButtonClicked(&mp);

		// leveli valimine nupu p�jal
		if (lvl > 0 && lvl <= this->levels.size())
		{
			this->currentLevel = this->levels[lvl - 1];
			this->currentLevel->reset();
			this->currentState = GameState::Playing;
		}
		
	// kui on pausil 
	} else if (this->currentState == GameState::Paused && mouse.button == sf::Mouse::Left)
	{
		// action on mitmendat nuppu vajutati
		sf::Vector2i mp = sf::Mouse::getPosition(*this->window);
		int action = this->pausedScreen.wasButtonClicked(&mp);

		if (action > 0 && action <= 3)
		{
			// Continue
			if (action == 1)
			{
				this->currentState = GameState::Playing;
			// To levels
			} else if (action == 2)
			{
				this->currentState = GameState::LevelSelect;
			// Reset
			} else if (action == 3)
			{
				this->currentLevel->reset();
				this->currentState = GameState::Playing;
			}
		}
	}

}


void Game::update(float deltaTime)
{
	this->pollEvents();

	if (this->currentState == GameState::Playing)
	{
		this->currentLevel->update(this->window, deltaTime);
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
		this->currentLevel->render(*this->window);
		break;

	case GameState::LevelSelect:
		this->levelSelectScreen.render(*this->window);
		break;

	case GameState::Paused:
		this->pausedScreen.render(*this->window);
		break;
	}

	this->window->display();
}
