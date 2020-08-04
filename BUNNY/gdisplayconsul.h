#pragma once
#include"GDisplay.h"
#include "BoardGame.h"
#include "TicTacTo.h"
#include "Game.h"
#include "CatchTheBunny.h"
class GameDisplayConsul :public GameDislay {
    public:        
        virtual void displayRuls()const = 0;
};
 
class  IksIgulDisplayConsul :public  GameDisplayConsul {
public:
    IksIgulDisplayConsul(){}
    virtual void displayRuls()const;
    virtual void DisplayTheGame(Game * game);
    virtual void PrintResoltOfTheGame( Game* game)const;
};


class CatchTheBunnyDisplayConsul :public  GameDisplayConsul {
public:
    virtual void displayRuls()const;
    virtual void DisplayTheGame(Game* game);
    virtual void PrintResoltOfTheGame(Game* game)const;
};
