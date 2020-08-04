#pragma once
#include <vector>
#include "Game.h"


//Abstract class
class BoardGame:public Game{
public:
	BoardGame(int rows, int columns) : _rows(rows), _columns(columns) {}
protected:
	int _rows;
	int _columns;
	std::vector<std::vector<char>> _board;
};
