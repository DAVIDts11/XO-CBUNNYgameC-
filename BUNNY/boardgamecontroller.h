#pragma once
#include<iostream>
#include "GameServer.h"
#include "Game.h"
#include "GDisplayConsul.h"
#include "TicTacTo.h"
#include "TicTacToEssyLevel.h"

#include "TicTacToMediumLevel.h"
#include "CatchTheBunny.h"
#include "CatchTheBunnyEssyLevel.h"
#include "CatchTheBunnyMediumLevel.h"

class BoardGameControler {
public:
	bool PlayTheGamr();
private:	
	void PlayCatchTheBunnyGame();
	void PlayTicTaToGame();
	Game* _newGame;
};

