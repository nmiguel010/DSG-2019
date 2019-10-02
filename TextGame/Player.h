#pragma once
#include "World.h"

class Player
{
	int c_x;
	int c_y;
	int coins;
	World& m_world;

public:
	Player(World& world);
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	int getX();
	int getY();

	int getcoin();
	void addcoin();

	//IN WORLD
	//bool canMove(int x, int y);

	/*bool Player::movePlayer(int myCellX, int myCellY, int wantedCellX, int wantedCellY);*/
	bool Player::movePlayer(int wantedCellX, int wantedCellY);

	bool Player::isCoin(int x, int y);
};

