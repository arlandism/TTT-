#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "board.h"
#include "movestrategy.h"
#include <map>
#include "vector"
#include "tttrules.h"

class Minimax: public MoveStrategy {
    
public:
    
    Minimax(std::string token){
        token_ = token;
    }
    int NextMove(Board);

private:
    
    std::multimap<int, int> ScorePossibleMoves(Board);
    std::string OtherToken(std::string);
    int ScoreMove(Board, int, std::string, int depth=20, bool maximizing=true);
    int Maximize(Board, std::string, int);
    int Minimize(Board, std::string, int);
    std::string GameWinner(Board);
    bool GameOver(Board);
    int HighestRatedMove(std::multimap<int, int>);
    int EvaluateGame(std::string, std::string);
    std::string token_;
};
#endif