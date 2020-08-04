#include "TicTacTo.h"
#include <iostream>
using namespace MyNameSpace;

TicTacTo::TicTacTo() :BoardGame(3, 3)
{
	for (int i = 0; i < 3; i++)
	{
		std::vector<char> temp;
		for (int j = 0; j < 3; j++)
			temp.push_back(Empty);
		_board.push_back(temp);
	}
	_state = InProgress;

	int goral= rand() % 2;
	if (goral == 1)
		_Player1Role = Iks, _Player2Role = Igul;
	else
		 _Player1Role = Igul , _Player2Role = Iks;
	
}

bool TicTacTo::performPlayerMove(const Move &PlaerMove)
{
	Move Move = PlaerMove;
	Move.fitToProg();
	if (Move.getRow() > 2 || Move.getRow() < 0 ||
		Move.getColumn() > 2 || Move.getColumn() < 0)
		return false;
		//throw "Invalid Move";

	else  if (_board[Move.getRow()][Move.getColumn()] == Empty)
		_board[Move.getRow()][Move.getColumn()] = _Player1Role;
	else return false;

	changeStateAfterMove(Move, 1);

	return true;
}



bool TicTacTo::changeStateAfterMove(const Move& Move, int numPlayer)
{

	GameState win;
	Role Player;
	if (numPlayer == 1)
	{
		win = PlayerWins;
		Player = _Player1Role;
	}

	else if (numPlayer == 2)
	{
		win = ComputerWins;
		Player = _Player2Role;
	}
	else throw "no such a player it can be only one or two";

	// checkin if smb win or tie 

	int counter = 0;
	for (int i = 0; i < 3; i++)
		if (_board[Move.getRow()][i] == Player)
			counter++;
	if (counter == 3)
		_state = win;
	else {
		counter = 0;
		for (int i = 0; i < 3; i++)
			if (_board[i][Move.getColumn()] == Player)
				counter++;
		if (counter == 3)
			_state = win;
		else {
			counter = 0;
			if (Move.getColumn() != 1 && Move.getRow() != 1)
			{
				if (Move.getColumn() == Move.getRow())
				{
					for (int i = 0; i < 3; i++)
						if (_board[i][i] == Player)
							counter++;
				}
				else {
					for (int i = 0; i < 3; i++)
						if (_board[i][2 - i] == Player)
							counter++;
				}
			}
			if (counter == 3)
				_state = win;
			else {
				bool tie = true;
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						if (_board[i][j] == Empty)
						{
							tie = false;
							break;
						}
				if (tie == true)
					_state = Tie;
			}
		}
	}

	return true;
}
