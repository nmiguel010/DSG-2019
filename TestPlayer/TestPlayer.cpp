#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TextGame/Player.h"
#include "../TextGame/GameLogic.h"
#include "../TextGame/World.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPlayer
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMoveLeft)
		{ 
			World world(10,10,3,3,9,9);
			Player player1(world, 'o'), player2(world, 'x');
			GameLogic gameLogic(player1, player2, world);
			player1.setX(3);
			player1.setY(3);
			int x = player1.getX();
			player1.moveLeft();
			int x_act = player1.getX();
			Assert::AreEqual(x-1, x_act);
		}
		
		TEST_METHOD(TestMoveRight)
		{
			World world(10, 10, 3, 3, 9, 9);
			Player player1(world, 'o'), player2(world, 'x');
			GameLogic gameLogic(player1, player2, world);
			player1.setX(3);
			player1.setY(3);
			int x = player1.getX();
			player1.moveRight();
			int x_act = player1.getX();
			Assert::AreEqual(x + 1, x_act);
		}

		TEST_METHOD(TestMoveUp)
		{
			World world(10, 10, 5, 5, 9, 9);
			Player player1(world, 'o'), player2(world, 'x');
			GameLogic gameLogic(player1, player2, world);
			player1.setX(3);
			player1.setY(3);
			int y = player1.getY();
			player1.moveUp();
			int y_act = player1.getY();
			Assert::AreEqual(y-1, y_act);
		}

		TEST_METHOD(TestMoveDown)
		{
			World world(10, 10, 2, 2, 9, 9);
			Player player1(world, 'o'), player2(world, 'x');
			GameLogic gameLogic(player1, player2, world);
			player1.setX(3);
			player1.setY(3);
			int y = player1.getY();
			player1.moveDown();
			int y_act = player1.getY();
			Assert::AreEqual(y + 1, y_act);
		}

		TEST_METHOD(TestAddCoin)
		{
			World world(10, 10, 2, 2, 9, 9);
			Player player1(world, 'o'), player2(world, 'x');
			GameLogic gameLogic(player1, player2, world);
			player1.setX(3);
			player1.setY(3);
			int c = player1.getcoin(1);
			player1.addcoin(1);
			int c_act = player1.getcoin(1);
			Assert::AreEqual(c + 1, c_act);
		}

	};
};