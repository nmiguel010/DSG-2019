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
			World world(10,10,1,1,10,10);
			Player player1(world), player2(world);
			GameLogic gameLogic(player1, player2, world);

			int x = 0;
			player1.moveLeft();
			int x_act = player1.getX();
			Assert::AreEqual(x, x_act);
		}

		/*TEST_METHOD(TestMoveRight)
		{
			int x = Player.getX();
			Player.moveRight();
			int x_act = Player.getX();
			Assert::AreEqual(x + 1, x_act);
		}

		TEST_METHOD(TestMoveUp)
		{
			int y = Player.getY();
			Player.moveUp();
			int y_act = Player.getY();
			Assert::AreEqual(y - 1, y_act);
		}

		TEST_METHOD(TestMoveDown)
		{
			int y = Player.getY();
			Player.moveDown();
			int y_act = Player.getY();
			Assert::AreEqual(y + 1, y_act);
		}

		TEST_METHOD(TestAddCoin)
		{
			int c = Player.getcoin();
			Player.addcoin();
			int c_act = Player.getcoin();
			Assert::AreEqual(c + 1, c_act);
		}*/

	};
}