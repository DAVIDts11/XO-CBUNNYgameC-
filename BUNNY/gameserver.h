#pragma once
#include <vector>
#include <iostream>
#include "Game.h"

class GameServer {
public:
	///...
	void addNewGame(std::unique_ptr<Game> GameToAdd);
	void deleteGame(int index);
	std::unique_ptr<Game> getGameByIndex(int index)const;
private:
	std::vector<std::unique_ptr<Game>> _Games;
};



