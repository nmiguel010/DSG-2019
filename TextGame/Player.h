#pragma once
#include "World.h"

class Player
{
	char m_id;
	int c_x=0;
	int c_y=0;
	int coins1=0;
	int coins2=0;
	World& m_world;

public:
	Player(World& world, char id);
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);

	int getcoin(char id);
	void addcoin(char id);

	//IN WORLD
	//bool canMove(int x, int y);

	/*bool Player::movePlayer(int myCellX, int myCellY, int wantedCellX, int wantedCellY);*/
	bool Player::movePlayer(int wantedCellX, int wantedCellY);

	bool Player::isCoin(int x, int y);
};

