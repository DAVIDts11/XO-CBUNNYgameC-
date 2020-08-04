#pragma once
#include "BoardGame.h"

using namespace MyNameSpace;

//Abstract class
class TicTacTo :public BoardGame {
public:
	
	TicTacTo();
	virtual bool performPlayerMove(const Move &PlaerMove);
	virtual GameState getGameState()const { return _state;}
	Role getPlayer1Role()const { return _Player1Role; }
	Role getPlayer2Role()const { return _Player2Role; }
	auto getTheBoard()const { return _board; }
protected:
	bool changeStateAfterMove(const Move& Move, int numPlayer);
	GameState _state;
private:	
	Role _Player1Role;  // User (Human player)
	Role _Player2Role;  //Computer (AI)
};


