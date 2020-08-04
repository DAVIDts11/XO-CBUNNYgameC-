#include "CatchTheBunnyEssyLevel.h"
#include "Move.h"

void CatchTheBunnyEssyLevel::ComputerNextAiMove()
{
	int direction;
	bool moved;
	position PrevPosition = _BunnyPosition;
	do
	{
		direction = rand() % 4;
		moved = false;
		
		switch (direction)
		{
			case(0):
			{
				if (_BunnyPosition.getCol() < 8)   //Right
				{
					_BunnyPosition.setCol(_BunnyPosition.getCol() + 1);
					moved = true;
				}
				break;
			}

			case(1):
			{
				if (_BunnyPosition.getCol() > 0)   //Left
				{
					_BunnyPosition.setCol(_BunnyPosition.getCol() - 1);
					moved = true;
				}
				break;
			}

			case(2):
			{
				if (_BunnyPosition.getRow() > 0)   //Up
				{
					_BunnyPosition.setRow(_BunnyPosition.getRow() - 1);
					moved = true;
				}
				break;
			}

			case(3):
			{
				if (_BunnyPosition.getRow() < 8)   //Down
				{
					_BunnyPosition.setRow(_BunnyPosition.getRow() + 1);
					moved = true;
				}
				break;
			}

		}

	} while (!moved);
	_board[PrevPosition.getRow()][PrevPosition.getCol()] = Empty;
	_board[_BunnyPosition.getRow()][_BunnyPosition.getCol()] = Bunny;
	changeStateAfterMove(); 

}
