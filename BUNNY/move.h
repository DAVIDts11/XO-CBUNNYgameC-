#pragma once
//#include "Game.h"

//using namespace MyNameSpace;
namespace MoveNamespase {
	enum  MoveDiraction { Right, Left, Up, Down };
}
using namespace MoveNamespase;
class Move {
public:
	Move():_row(0),_col(0), _moveDiraction(Right) {}
	Move(int row, int col) :_row(row), _col(col),_moveDiraction(Right) {}
	Move(MoveDiraction  Diraction) :_moveDiraction(Diraction),_row(0),_col(0){}
	void fitToProg();
	int getRow()const { return _row; }
	int getColumn()const { return _col; }
	MoveDiraction getMoveDirection() const {return _moveDiraction;}
	void setDiraction(MoveDiraction Move) { _moveDiraction = Move; }
private:
	MoveDiraction _moveDiraction;
	int _row;
	int _col;
};


//class BoadrGameMove :public Move {
//public:
//	BoadrGameMove(int row, int col) :_row(row), _col(col) {}
//	int getRow()const { return _row; }
//	int getColumn()const { return _col; }
//private:
//	int _row;
//	int _col;
//
//};
