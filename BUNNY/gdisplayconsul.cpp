
#include "GDisplayConsul.h"
#include "TicTacTo.h"
#include "TicTacToEssyLevel.h"
using namespace MyNameSpace;
using namespace std;
void IksIgulDisplayConsul::displayRuls() const
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "Put you're symbol into the empty square ('-')" << endl
		<< "Then the second player (the computer) will put his " << endl
		<< "the one who fill the hole line or horizontal - win" << endl;

	//cin.get(); 
	system("pause");
}
void IksIgulDisplayConsul::DisplayTheGame(Game* game)
{
	TicTacTo* ThisGame = dynamic_cast<TicTacTo*>(game);
	std::cout<< std::endl << std::endl;
	std::cout << "IKS IGOL GAME (for Windows)" << std::endl<<std::endl;
	std::cout << "The Game Status is" << game->getGameState()<<std::endl<<std::endl;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			//if(game=>)
			if (ThisGame->getTheBoard()[i][j] == Empty)
				std::cout << "  -  ";
			else if (ThisGame->getTheBoard()[i][j] == Iks)
				std::cout << "  X  ";
			else if (ThisGame->getTheBoard()[i][j] == Igul)
				std::cout << "  O  ";
		std::cout << std::endl;
	}
}

void IksIgulDisplayConsul::PrintResoltOfTheGame( Game* game) const
{
	cout << endl;

	if (game->getGameState() == ComputerWins)
		cout << "ComputerWins" << endl;
	else
		if (game->getGameState() == PlayerWins)
			cout << "PlayerWins" << endl;
		else
			if (game->getGameState() == Tie)
				cout << "Tie" << endl;
}

void CatchTheBunnyDisplayConsul::displayRuls() const
{
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "The kid ('K') should catch the bunny ('B') in maximum 16 moves" << endl
		<< "You playing for a  kid , and the computer for the bunny" << endl
		<< "Each one makes one step at the time - you going first and then computer" << endl
	    << "You can move  Right,Left,Up,Down (using 'R','L','U',''D)" << endl
	    << "If you caught the bunny -you win , if you use all you moves and dont catch it -computer win. " << endl;
	    
	system("pause");
}

void CatchTheBunnyDisplayConsul::DisplayTheGame(Game* game)
{
	CatchBunnyGame* ThisGame = dynamic_cast<CatchBunnyGame*>(game);
	std::cout << std::endl << std::endl;
	std::cout << "Catch The Bunny Game (for Windows)" << std::endl << std::endl;
	std::cout << "The Game Status is" << game->getGameState() << std::endl << std::endl;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			//if(game=>)
			if (ThisGame->getTheBoard()[i][j] == Empty)
				std::cout << "  -  ";
			else if (ThisGame->getTheBoard()[i][j] == Bunny)
				std::cout << "  B  ";
			else if (ThisGame->getTheBoard()[i][j] == Kid)
				std::cout << "  K  ";
		std::cout << std::endl;
	}
}

void CatchTheBunnyDisplayConsul::PrintResoltOfTheGame(Game* game) const
{
	cout << endl;

	if (game->getGameState() == ComputerWins)
		cout << "ComputerWins" << endl;
	else
		if (game->getGameState() == PlayerWins)
			cout << "PlayerWins" << endl;
}
