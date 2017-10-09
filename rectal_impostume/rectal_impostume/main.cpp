#include <stdlib.h>
#include <stdio.h>

#include "GameLoop.h"


int main(void)
{
	//start the game
	RaptorEngine::Core::GameLoop gameLoop;
	gameLoop.run();

	//exit game
	exit(EXIT_SUCCESS);
}
