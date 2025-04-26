#include <iostream>
#include "Game.h"

int main()
{
	// Game engine
	Game game;

	while (game.isRunning()) 
	{
		//Update
		game.update();

		//Render
		game.render();
	}
	return 0;
}