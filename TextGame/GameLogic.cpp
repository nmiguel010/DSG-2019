#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"

GameLogic::GameLogic(Player& player1, Player& player2, World& world)
	: mplayer1(player1), mplayer2(player2), m_world(world)
{
	
}


GameLogic::~GameLogic()
{
}

void GameLogic::processInput()
{
	if (!System::keyHit())
		return; //no keyboard event to be processed


	while (System::keyHit())
	{
		char c = System::getNextKey();
		switch (c)
		{

		case 'a':
			mplayer1.moveLeft();
			break;
		case 's': mplayer1.moveUp();
			break;
		case 'd': mplayer1.moveDown();
			break;
		case 'f': mplayer1.moveRight();
			break;
		case '4': mplayer2.moveLeft();
			break;
		case '8': mplayer2.moveUp();
			break;
		case '2': mplayer2.moveDown();
			break;
		case '6': mplayer2.moveRight();
			break;
		case 27:
			esc = true;
			//'Esc' key pressed. Exit the game
			return ;
		}
	}
}

bool GameLogic::gameHasEnded()
{
	if (esc == true) 
		return true;
	else
		return false;
}

void GameLogic::gamePoints()
{
	coins1 = GameLogic::mplayer1.getcoin();
	coins2 = GameLogic::mplayer2.getcoin();
	cout << "Player1 coins: " << coins1 << '\n';
	cout << "Player2 coins: " << coins2;
}