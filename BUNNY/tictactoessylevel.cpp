#include "TicTacToEssyLevel.h"

void TicTacToEssyLevel::ComputerNextAiMove()
{
	int compRow;
	int compColmn;
	do
	{
		compRow = rand() % 3;
		compColmn = rand() % 3;
	} while (_board[compRow][compColmn]!=Empty);
	_board[compRow][compColmn] = this->getPlayer2Role();
	Move compMove(compRow, compColmn);   
	changeStateAfterMove(compMove, 2);

}
