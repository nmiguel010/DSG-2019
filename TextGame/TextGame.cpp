// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"


int main()
{
	World world("file.csv");
	Player player1(world), player2(world);
	GameLogic gameLogic(player1, player2, world);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}

    return 0;
}

