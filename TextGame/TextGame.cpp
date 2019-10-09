// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"
#include "System.h"


int main()
{
	World world("file.csv");
	//World world(5,5);
	Player player1(world), player2(world);
	GameLogic gameLogic(player1, player2, world);

	while (!gameLogic.gameHasEnded())
	{
		//draw only the world
		world.draw();
		//draw the coins
		world.drawCoins();
		gameLogic.processInput();
		//game stadistics
		gameLogic.gamePoints();

		//no infinite maze
		System::clear();
	}

    return 0;
}

