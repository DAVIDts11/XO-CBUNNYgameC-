#include "CatchTheBunny.h"
#include <iostream>

CatchBunnyGame::CatchBunnyGame() :BoardGame(9, 9)
{
	//int row = rand() % 9;
	//int col;
	//do
	//{
	//	col = rand() % 9;
	//} while (col==row);
	//
	//_KidPosition.setCol(col);
	//_KidPosition.setRow(row);
	for (int i = 0; i < 9; i++)
	{
		std::vector<char> temp;
		for (int j = 0; j < 9; j++)
			temp.push_back(Empty);
		_board.push_back(temp);
	}

	_KidPosition.setCol(0);
	_KidPosition.setRow(0);
	_BunnyPosition.setCol(8);
	_BunnyPosition.setRow(8);
	_board[_KidPosition.getRow()][_KidPosition.getRow()] = Kid;
	_board[_BunnyPosition.getRow()][_BunnyPosition.getCol()] = Bunny;
	_MoveCounter = 0;
	_state = InProgress;
}

bool CatchBunnyGame::performPlayerMove(const Move &PlaerMove)
{

	position PrevPosition = _KidPosition;
	switch (PlaerMove.getMoveDirection())
	{
	case(Down):
		if (_KidPosition.getRow() < 8)
		{
			_KidPosition.setRow(_KidPosition.getRow() + 1);
			break;
		}
		else return false;
	case (Up):
		if (_KidPosition.getRow() >0)
		{ 
			_KidPosition.setRow(_KidPosition.getRow() - 1);
			break;
		}
		else return false;

	case (Left):
		if (_KidPosition.getCol() > 0)
		{ 
			_KidPosition.setCol(_KidPosition.getCol() - 1);
			break;
		}
		else return false;
	case (Right):
		if (_KidPosition.getCol() < 8)
		{ 
			_KidPosition.setCol(_KidPosition.getCol() + 1);
			break;
		}
		else return false;
	default:
		return false;
	}
	_MoveCounter++;
	_board[PrevPosition.getRow()][PrevPosition.getCol()] = Empty;
	_board[_KidPosition.getRow()][_KidPosition.getCol()] = Kid;
	changeStateAfterMove(); ////
	return true;
}

bool CatchBunnyGame::changeStateAfterMove()
{
	if ((_KidPosition.getRow() == _BunnyPosition.getRow()) &&
		abs(_KidPosition.getCol() - _BunnyPosition.getCol())==1)
		_state = PlayerWins;
	if ((_KidPosition.getCol() == _BunnyPosition.getCol()) &&
		abs(_KidPosition.getRow()-_BunnyPosition.getRow())==1)
		_state = PlayerWins;

	if (_MoveCounter > MOVESAMOUNT)
		_state = ComputerWins;

	return true;
}
