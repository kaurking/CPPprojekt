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
	this->levelSelect = false;
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
			if (this->ev.key.code == sf::Keyboard::Escape) 
			{
				if (this->levelSelect)
					this->levelSelect = false;
				else this->levelSelect = true;
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (this->ev.mouseButton.button == sf::Mouse::Left && levelSelect)
			{
				sf::Vector2i mp = sf::Mouse::getPosition(*this->window);
				int lvl = this->levelSelectScreen.wasButtonClicked(&mp);
				switch (lvl)
				{
				case 0:
					std::cout << 0 << '\n';
					break;
				case 1:
					// Level 1
					std::cout << 1 << '\n';
					break;
				case 2:
					// Level 2
					std::cout << 2 << '\n';
					break;
				case 3:
					// Level 3
					std::cout << 3 << '\n';
					break;
				default: throw("WHaT!HOW?");
				}

				levelSelect = false;
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (!this->levelSelect) 
	{
		this->player.update(this->window);
	}
}

void Game::render()
{
	this->window->clear();

	if (this->levelSelect)
	{
		this->window->clear(sf::Color(40, 40, 40, 100));
		// Level select screen siia
		this->levelSelectScreen.render(this->window);
	}
	else
	{
		// Kui on levelis
		this->player.render(this->window);
	}
	

	

	this->window->display();
}
