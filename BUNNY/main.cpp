#include <iostream>
#include "TicTacTo.h"
#include "TicTacToEssyLevel.h"
#include "GDisplayConsul.h"
#include "BoardGameController.h"
#include "Move.h"
using namespace std;

int main(void)
{
	//int randomNum;

	//for (int i = 0; i < 20; i++)
	//{

	//	randomNum = rand() % 2;
	//	cout << randomNum<<endl;

	//}

	TicTacToEssyLevel* newGame = new TicTacToEssyLevel;
	CatchTheBunnyEssyLevel* newGame2 = new CatchTheBunnyEssyLevel;
	BoardGameControler bc;
	bc.PlayTheGamr();


	//int r, c;

	//do
	//{
	//	a.DisplayTheGame(newGame);
	//	cout << "Enter The Row Number(0-2) :  ";
	//	cin >> r;
	//	cout << "Enter The Column Number(0-2) :  ";
	//	cin >> c;
	//	Move m1(r, c);
	//	bool check = newGame->performPlayerMove(m1);
	//	//std::cout << check;
	//
	//	newGame->ComputerNextAiMove();
	//	a.DisplayTheGame(newGame);

	//} while (newGame->getGameState()==InProgress);


	return 0;
}