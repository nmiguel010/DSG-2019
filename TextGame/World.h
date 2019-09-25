#pragma once
#include "Timer.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	int width;
	int height;

	int CELLS;

	vector<char> m_cells;

	bool m_esc; 

	

	void drawMaze();

public:
	World(string nameFile);
	~World();

	void draw();
};