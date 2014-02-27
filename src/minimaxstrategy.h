#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "board.h"
#include "movestrategy.h"
#include <map>
#include "vector"

class MinimaxStrategy:public MoveStrategy {
    
public:
    
    int NextMove(Board);
    void set_token(std::string);

private:
    int EvaluateMove(Board, int, std::string, bool=false);
    int MinMax(int, std::string);
    int HighestScoringMove(Board, std::string);
    int EvaluateGame(std::string);
    std::string token_;
};
#endif
