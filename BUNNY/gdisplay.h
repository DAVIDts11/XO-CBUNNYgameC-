#pragma once
#include <iostream> 
#include "Game.h"
//Interface
class GameDislay {
public:
	//virtual void DisplayTheGame(std::unique_ptr<Game> game) const;
	virtual void DisplayTheGame(Game *game)=0 ;
	virtual void PrintResoltOfTheGame(Game* game)const=0;
};


