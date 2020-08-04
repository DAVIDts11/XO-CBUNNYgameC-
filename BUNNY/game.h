#pragma once
#include "Move.h"


namespace MyNameSpace
{
	enum  GameState { PlayerWins, ComputerWins, Tie, InProgress };
	enum  Role { Igul, Empty,Iks};  //it's rrepresent both - the player role and square status (the order is importent)
	enum  KBRole { Kid=3, Bunny };   //very importent for AI
	//enum  MoveDiraction { Right, Left, Up, Down };
}

using namespace MyNameSpace;

//Interfase
class Game {
	public:
		virtual void ComputerNextAiMove() = 0;
		virtual bool performPlayerMove(const Move &PlaerMove) = 0;
		virtual GameState getGameState() const = 0;
};
