#include "stdafx.h"
#include "Player.h"
#include "World.h"

Player::Player(World& world) : m_world(world)
{
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

int Player::getcoin()
{
	return coins;
}

void Player::addcoin()
{
	coins += 1;
}

//bool Player::movePlayer(int myCellX, int myCellY, int wantedCellX, int wantedCellY)
bool Player::movePlayer(int wantedCellX, int wantedCellY)
{
	return m_world.canMove(wantedCellX, wantedCellY);
}

//return if in the position is money
bool Player::isCoin(int x, int y)
{
	int cell = World::calcPosition(x, y);
	if (World::m_coin == World::m_cells[cell])
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