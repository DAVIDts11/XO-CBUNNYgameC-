#pragma once
#pragma once
#include "BoardGame.h"
#include "Move.h"
using namespace MyNameSpace;
using namespace std;
#define MOVESAMOUNT 16

//Abstract class
class CatchBunnyGame :public BoardGame {
public:
	CatchBunnyGame();
	virtual bool performPlayerMove(const Move & PlaerMove);
	virtual GameState getGameState()const { return _state; }
	auto getTheBoard()const { return _board; }
	int getMoveCounter()const { return _MoveCounter; }

		class position {
		public:
			position():_col(0),_row(0){}
			position(int row,int col): _col(col),_row(row) {}
			int getRow()const { return _row; }
			int getCol()const { return _col; }
			void setRow(int row) { _row = row; }
			void setCol(int col) { _col = col; }
		private:
			int _col;
			int _row;
		};

protected:
	bool changeStateAfterMove();
	GameState _state;
	position _KidPosition;  // user
	position _BunnyPosition; // computer  
	int _MoveCounter;
};