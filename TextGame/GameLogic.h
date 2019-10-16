#pragma once

#include "Player.h"
#include "World.h"

class GameLogic
{

	Player &mplayer1, &mplayer2;
	World& m_world;
	bool esc = false;

	int coins1;
	int coins2;

public:
	GameLogic(Player& player1, Player& player2, World& world);
	~GameLogic();

	void processInput();
	bool gameHasEnded();
	void GameLogic::gamePoints();
};

