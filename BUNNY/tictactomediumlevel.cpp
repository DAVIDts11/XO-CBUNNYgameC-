#include "TicTacToMediumLevel.h"
#include <iostream>
void TicTacMediumLevel::ComputerNextAiMove()
{
	int sum;
	bool foundSeq=false;
	int i,j;
	int compRow , compColmn;
	for (i = 0; i < 3; i++)
	{
		sum = _board[i][0] + _board[i][1] + _board[i][2];
		if (sum == 5 || sum == 1)
		{
			foundSeq = true;
			break;
		}
	}
	if (foundSeq)
		{
			j = 0;
			while (_board[i][j] != 1)
			{
				j++;
			}
			compRow = i;
			compColmn = j;
		}
	else
		{

			for (i = 0; i < 3; i++)
			{
				sum = _board[0][i] + _board[1][i] + _board[2][i];
				if (sum == 5 || sum == 1)
				{
					foundSeq = true;
					break;
				}
			}
			if (foundSeq)
			{
				j = 0;
				while (_board[j][i] != 1)
				{
					j++;
				}
				compRow = j;
				compColmn = i;
			}
			else
			{
				sum = 0;
				for (i = 0; i < 3; i++)
				{
					sum += _board[i][i];
				}
					if (sum == 5 || sum == 1)
					{
						foundSeq = true;
					}
					if (foundSeq)
					{
						j = 0;
						while (_board[j][j] != 1)
						{
							j++;
						}
						compRow = j;
						compColmn = j;
					}
					else
					{
						sum = 0;
						for (i = 0; i < 3; i++)
						{
							sum += _board[i][2-i];
						}
						if (sum == 5 || sum == 1)
						{
							foundSeq = true;
						}
						if (foundSeq)
						{
							j = 0;
							while (_board[j][2-j] != 1)
							{
								j++;
							}
							compRow = j;
							compColmn = 2-j;
						}
						else
						{
							do
							{
								compRow = rand() % 3;
								compColmn = rand() % 3;
							} while (_board[compRow][compColmn] != Empty);
						}

					}
				

			}



		}


	_board[compRow][compColmn] = this->getPlayer2Role();
	Move compMove(compRow, compColmn);
	changeStateAfterMove(compMove, 2);
}
