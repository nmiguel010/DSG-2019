#pragma once
#include "Timer.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	int m_width;
	int m_height;

	//int coins1;
	//int coins2;

	int CELLS;
	
public :
	
	vector<char> m_cells;

	bool m_esc;
	int totalCoins=10;

	//Caracteres
	const char m_coin = '*';
	const char m_player1 = 'o';
	const char m_player2 = 'x';
	const char m_nothing = '.';
	const char m_wall = '?';

	void drawMaze();

	World(string nameFile);

	~World();

	World(int width, int height, int xPlayer1, int iPlayer1, int xPlayer2, int iPlayer2);

	void draw();

	int calcPosition(int x, int y);

	void drawCoins();

	bool canMove(int x, int y);

	void findPlayer(char id, int& x, int& y);

	int coinsCalculate();
};