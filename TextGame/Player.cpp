#include "stdafx.h"
#include "Player.h"
#include "World.h"
using namespace std;

Player::Player(World& world, char id) : m_world(world)
{
	world.findPlayer(id, c_x, c_y);
}

Player::~Player()
{
}

//¿can move? then move, ¿can´t move? stay
void Player::moveUp()
{
	//if (movePlayer(getX(), getY(), getX(), getY()-1))
	if (movePlayer(getX(), getY() - 1))
	{
		c_y -= 1;
	}
}

void Player::moveDown()
{ 
	/*if (movePlayer(getX(), getY(), getX(), getY()+1))*/
	if (movePlayer(getX(), getY() + 1))
	{
		c_y += 1;
	}
}

void Player::moveRight()
{
	//if (movePlayer(getX(), getY(), getX()+1, getY()))
	if (movePlayer(getX() + 1, getY()))
	{
		c_x += 1;
	}
}

void Player::moveLeft()
{
	//if (movePlayer(getX(), getY(), getX()-1, getY()))
	if (movePlayer(getX() - 1, getY()))
	{
		c_x -= 1;
	}
}

int Player::getX()
{
	return c_x;
}

int Player::getY()
{
	return c_y;
}

void Player::setX(int x)
{
	c_x = x;
}

void Player::setY(int y)
{
	c_y = y;
}
int Player::getcoin()
{
	return coins;
}

void Player::addcoin()
{
	coins += 1;
	m_world.totalCoins -= 1;
}

//bool Player::movePlayer(int myCellX, int myCellY, int wantedCellX, int wantedCellY)
bool Player::movePlayer(int wantedCellX, int wantedCellY)
{
	if (m_world.canMove(wantedCellX, wantedCellY))
	{
		//hacer cambio de contenido si se puede mover
		int posAct = m_world.calcPosition(c_x, c_y);
		int posNew = m_world.calcPosition(wantedCellX, wantedCellY);

		m_world.m_cells[posNew] = m_world.m_cells[posAct];
		m_world.m_cells[posAct] = '.';
	}
	return m_world.canMove(wantedCellX, wantedCellY);
}

//return if in the position is money
bool Player::isCoin(int x, int y)
{
	int cell = m_world.calcPosition(x, y);
	if (m_world.m_coin == m_world.m_cells[cell])
	{
		addcoin();
		return true;
	}
	else
	{
		return false;
	}
}

//IN WORLD
//bool Player::canMove(int x, int y)
//{
//	//width 100
//	int cell = y * 100 + x;
//	
//	//count coin = '?' and move
//	if ('?' == m_world.m_cell[cell])
//	{
//		return true;
//	}
//	//no move wall = '#'
//	else if ('#' == m_world.m_cell(cell))
//	{
//		return false;
//	}
//	//move 
//	else
//	{
//		return true;
//	}
//}