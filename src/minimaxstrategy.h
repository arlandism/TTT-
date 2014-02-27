#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "board.h"
#include "movestrategy.h"
#include <map>
#include "vector"
#include "gamesettings.h"
#include "tttrules.h"

class MinimaxStrategy: public MoveStrategy {
    
public:
    
    MinimaxStrategy(GameSettings *settings){
        settings_ = settings;
    }
    int NextMove(Board);
    void set_token(std::string);

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
