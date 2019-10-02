#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"

GameLogic::GameLogic(Player& player1, Player& player2, World& world)
	: m_player1(player1), m_player2(player2), m_world(world)
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

		case 'a': m_player1.moveLeft();
			break;
		case 's': m_player1.moveUp();
			break;
		case 'd': m_player1.moveDown();
			break;
		case 'f': m_player1.moveRight();
			break;
		case '4': m_player2.moveLeft();
			break;
		case '8': m_player2.moveUp();
			break;
		case '2': m_player2.moveDown();
			break;
		case '6': m_player2.moveRight();
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
	coins1 = GameLogic::m_player1.getcoin();
	coins2 = GameLogic::m_player2.getcoin();
	cout << "Player1 coins: " + coins1 + '\n';
	cout << "Player2 coins: " + coins2;
}