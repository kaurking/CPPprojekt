#include <iostream>
#include "Game.h"

int main()
{
	// Game engine
	Game game;

	// Kell mängu jaoks
	sf::Clock clock;

	// Game loop
	while (game.isRunning()) 
	{
		// Aja jaoks - deltaTime on aeg eelmise ja praeguse frame'i vahel. 60 fps = 0.0167f
		// 120 fps = 0,0083f
		float deltaTime = clock.restart().asSeconds();

		//Update
		game.update(deltaTime);

		//Render
		game.render();
	}
	return 0;
}