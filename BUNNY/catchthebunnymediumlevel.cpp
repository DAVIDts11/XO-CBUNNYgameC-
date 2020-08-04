#include "CatchTheBunnyMediumLevel.h"
#include<iostream>
#include <vector>

void CatchTheBunnyMediumLevel::ComputerNextAiMove()
{
	position PrevPosition = _BunnyPosition;

	vector<int> optinalMoves(4,-100);   // -100 = -infinity
	
	if (_BunnyPosition.getCol() < 8) //if it can to move right
		optinalMoves[0] = abs((_BunnyPosition.getCol()+1) - _KidPosition.getCol())
		+ abs(_BunnyPosition.getRow() - _KidPosition.getRow());
		

	if (_BunnyPosition.getCol() > 0) //if it can to move left
		optinalMoves[1] = abs((_BunnyPosition.getCol()-1) - _KidPosition.getCol())
		+ abs(_BunnyPosition.getRow() - _KidPosition.getRow());

	if (_BunnyPosition.getRow() > 0) //if it can to move up
		optinalMoves[2] = abs(_BunnyPosition.getCol() - _KidPosition.getCol())
		+ abs((_BunnyPosition.getRow()-1) - _KidPosition.getRow());

	if (_BunnyPosition.getRow() < 8) //if it can to move down
		optinalMoves[3] = abs(_BunnyPosition.getCol() - _KidPosition.getCol())
		+ abs((_BunnyPosition.getRow()+1) - _KidPosition.getRow());

	int max = -1;
	int tempI{};
	if (_MoveCounter < 6)
	{
		for (int i = 1; i < 3; i++)
		{
			if (optinalMoves[i] > max)  //= becouse left is second .
			{
				max = optinalMoves[i];
				tempI = i;
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (optinalMoves[i] >= max)  //= becouse left is second .
			{
				max = optinalMoves[i];
				tempI = i;
			}
		}
	}



	//R L U D

	switch (tempI)
	{
		case(0) :
			_BunnyPosition.setCol(_BunnyPosition.getCol() + 1);
		break;
		case(1):
			_BunnyPosition.setCol(_BunnyPosition.getCol() - 1);
			break;
		case(2):
			_BunnyPosition.setRow(_BunnyPosition.getRow() - 1);
			break;
		case(3):
			_BunnyPosition.setRow(_BunnyPosition.getRow() + 1);
			break;
	}


	_board[PrevPosition.getRow()][PrevPosition.getCol()] = Empty;
	_board[_BunnyPosition.getRow()][_BunnyPosition.getCol()] = Bunny;
	changeStateAfterMove();

}
