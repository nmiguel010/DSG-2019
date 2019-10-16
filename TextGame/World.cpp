#include "stdafx.h"
#include "World.h"
#include "Player.h"
#include "GameLogic.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "System.h"
#include "stdafx.h"
#include <stdio.h>
#include <istream>
#include <vector>
using namespace std;



World::World(std::string nameFile)
{
	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//TODO: initalize everything else
	//...
	ifstream ficheroEntrada;
	ficheroEntrada.open(nameFile); //open
	char read; //la coma

	ficheroEntrada >> m_width >> read >> m_height;
	CELLS = m_width * m_height;
	m_cells = vector<char>(CELLS);
	//read the rest of the file
	for (int i = 0; i < CELLS; i++)
	{
		ficheroEntrada >> m_cells[i];
	}
	/*while (getline(ficheroEntrada, read)) {
		cout << read << "\n";
	}*/
}

World::~World()
{
}

World::World(int width, int height)
{
	m_width = width;
	m_height = height;

	//initialize();
}
void World::draw()
{
	drawMaze();

	//int numcells = width * height;
	//for (int i = 0; i < numcells; i++)
	//{
	//	cout << m_cells[i]; 
	//}

	//TODO: -write the points each player has
	//coins1 = GameLogic::m_player1.getcoin();
	//coins2 = GameLogic::m_player2.getcoin();
	//AQUI NO

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color

	//std::cout << m_timer.getElapsedTime() << "   ";
	cout << "time:" << m_timer.getElapsedTime() << "   ";
}

void World::drawMaze()
{
	System::clear();

	//TODO: -draw the maze: walls and each of the cells

	int n;

	for (int j = 0; j < m_width; j++)
	//for (int i = 0; i < m_height; i++)
	{
		for (int i = 0; i < m_height; i++)
		//for (int j = 0; j < m_width; j++)
		{
			n = calcPosition(i, j);
			cout << m_cells[n];
		}
		cout << '\n';
	}

	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void World::drawCoins()
{
	//travel the world and when coin draw coin in the world
	for (int i = 0; i < m_height; i++)
	{
		if (m_coin == m_cells[i])
		{
			cout << m_cells[i];
		}
	}
}

bool World::canMove(int x, int y)
{
	//width 100
	//int cell = y * width + x;
	int cell = calcPosition(x, y);

	//no count coin = '?' and move
	if (m_coin == m_cells[cell])
	{
		return true;
	}
	//no move wall = '#'
	else if (m_wall == m_cells[cell])
	{
		return false;
	}
	//move 
	else
	{
		return true;
	}
}

int World::calcPosition(int x, int y)
{
	int cellP = y * m_width + x;
	return cellP;
}

void World::initialize()
{
	cout << " " << " " << " " << " " << "?" << "\n";
	cout << " " << "?" << " " << "#" << " " << "\n";
	cout << " " << " " << " " << " " << " " << "\n";
	cout << " " << "#" << " " << "?" << " " << "\n";
	cout << " " << "?" << " " << " " << "?" << "\n";
}