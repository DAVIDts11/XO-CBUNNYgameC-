#include "BoardGameController.h"

using namespace std;

bool BoardGameControler::PlayTheGamr()
{
	bool continiumPlaying;
	do
	{
	std::system("cls");
	cout << "Welcome To The Games " << endl;
	bool CorectChose = true;
	int ChosenGame , ChosenLevel;
	do
	{
		//choose the game
		if (CorectChose==false)
			cout << "Invalid Input , please try again. " << endl;
		cout << "Please choose  the game: " << endl;
		cout << "For Tic-Tac-To Game press 1 " << endl;
		cout << "For Catch-The-Bunny  Game press 2 " << endl;
		cin >> ChosenGame;
		if (ChosenGame != 1 && ChosenGame != 2)
			CorectChose = false;
		else CorectChose = true;
	} while (!CorectChose);

	/////

	do
	{
		//choose the level
		if (CorectChose == false)
			cout << "Invalid Input , please try again. " << endl;
		cout << "Please choose  the level of the game: " << endl;
		cout << "For Essy level press 1 " << endl;
		cout << "For Medium level  Game press 2 " << endl;
		cin >> ChosenLevel;
		if (ChosenLevel != 1 && ChosenLevel != 2)
			CorectChose = false;
		else CorectChose = true;
	} while (!CorectChose);



	if (ChosenGame == 1)

	{
		if (ChosenLevel == 1)
			_newGame = new TicTacToEssyLevel;
		else 
			_newGame = new TicTacMediumLevel;
		PlayTicTaToGame();
	}
	else {
		if (ChosenLevel == 1)
			_newGame = new CatchTheBunnyEssyLevel;
		else
			_newGame = new CatchTheBunnyMediumLevel;
		PlayCatchTheBunnyGame();
	}

	//_newGame = new TicTacToEssyLevel; ////temprerary (zmani)
	//_newGame = new CatchTheBunnyEssyLevel; 
	//CatchTheBunnyDisplayConsul d;
	//d.displayRuls();
	//d.DisplayTheGame(_newGame);
	//PlayCatchTheBunnyGame();
	//PlayTicTaToGame();
	char chose;
	do
	{
		cout << "If you want to exit program - enter 'X' . To continium playing enter 'C'";
		fflush(stdin);
		cin >> chose;
	} while (chose!='X' && chose!='C');
	if (chose == 'X')
		continiumPlaying = false;
	else
		continiumPlaying = true;

	
	} while (continiumPlaying);
	return true;
}



void BoardGameControler::PlayCatchTheBunnyGame()
{
	CatchTheBunnyDisplayConsul a;
	a.displayRuls();
	char diraction;
	MoveDiraction ChosenMove;
	Move m1;
	bool check = false;
	bool ch;
	do
	{
		std::system("cls");
		a.DisplayTheGame(_newGame);
		do
		{ 
			ch = true;
			cout << endl;
			CatchBunnyGame* p = dynamic_cast<CatchBunnyGame*>(_newGame);

			cout << "You playing  with a 'K' " << endl;
			cout << " Remained moves amount: " <<( MOVESAMOUNT - p->getMoveCounter()) << endl;
			cout << "Where do you want to move? ('R'-right,'L'-left,'U'-up,'D'-down) :  ";
			fflush(stdin);
			cin >> diraction;
			switch (diraction)
			{
			case('R'):
			{
				ChosenMove = Right;
				break;
			}
			case('L'):
			{
				ChosenMove = Left;
				break;
			}
			case('U'):
			{
				ChosenMove = Up;
				break;
			}
			case('D'):
			{
				ChosenMove = Down;
				break;
			}
			default:
			{
				ch=false;
				check = false;
				break;
			}
			}
			if (ch) {
				 m1.setDiraction(ChosenMove);			
			   	 check = _newGame->performPlayerMove(m1);
			}

			if (check == false)
				cout << "IVALID MOVE" << endl;
		} while (check != true);
		if (_newGame->getGameState() == InProgress)
		{
			_newGame->ComputerNextAiMove();
			std::system("cls");
			a.DisplayTheGame(_newGame);
		}
	} while (_newGame->getGameState() == InProgress);
	std::system("cls");
	a.DisplayTheGame(_newGame);
	a.PrintResoltOfTheGame(_newGame);
}






void BoardGameControler::PlayTicTaToGame()
{
	IksIgulDisplayConsul a;
	a.displayRuls();
	int r, c;
	bool check = false;
	do
	{
		std::system("cls");
		a.DisplayTheGame(_newGame);
		do
		{
			cout << endl;
			TicTacTo* p = dynamic_cast<TicTacTo*>(_newGame);
			if (p->getPlayer1Role() == Iks)
				cout << "You playing  with a 'X' " << endl;
			else
				cout << "You playing  with a 'O' " << endl;
			cout << "Enter The Row Number(1-3) :  ";
			cin >> r;
			cout << "Enter The Column Number(1-3) :  ";
			cin >> c;
			Move m1(r, c);
			check = _newGame->performPlayerMove(m1);
			if (check == false)
				cout << "IVALID MOVE" << endl;
		} while (check != true);
		if (_newGame->getGameState() == InProgress)
		{
			_newGame->ComputerNextAiMove();
			std::system("cls");
			a.DisplayTheGame(_newGame);
		}


	} while (_newGame->getGameState() == InProgress);
	std::system("cls");
	a.DisplayTheGame(_newGame);
	a.PrintResoltOfTheGame(_newGame);
}
