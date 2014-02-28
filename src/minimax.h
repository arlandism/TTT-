#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "board.h"
#include "movestrategy.h"
#include <map>
#include "vector"
#include "gamesettings.h"
#include "tttrules.h"

class Minimax: public MoveStrategy {
    
public:
    
    Minimax(std::string token, GameSettings *settings){
        settings_ = settings;
        token_ = token;
    }
    int NextMove(Board);

private:
    
    GameSettings *settings_;
    
    bool ShouldPrune(int, int);
    std::multimap<int, int> EvaluateRemainingMoves(Board);
    int BestScoreOfChildren(Board, std::string, int);
    int HighestRatedMove(std::multimap<int, int>);
    int EvaluateMove(Board, int, std::string, int=-1, int=1, bool=false);
    int EvaluateGame(std::string, std::string);
    std::string token_;
};
#endif