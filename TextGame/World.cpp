#include "stdafx.h"
#include "World.h"
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
	

	World::CELLS = width * height;
}


World::~World()
{
}

World::World(int width, int height)
{

}
void World::draw()
{
	drawMaze();

	//TODO: -write the points each player has
	

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";

}


void World::drawMaze()
{
	System::clear();

	//TODO: -draw the maze: walls and each of the cells

	int n;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			n = World::calcPosition(i, j);
			cout << m_cells[n];
		}
		cout << '\n';
	}



	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

bool World::canMove(int x, int y)
{
	//width 100
	int cell = y * width + x;

	//count coin = '?' and move
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
	int cellP = y * width + x;
}