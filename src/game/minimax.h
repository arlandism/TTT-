#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <string>
#include <map>
#include <vector>
#include "board.h"
#include "movestrategy.h"
#include "tttrules.h"

class Minimax: public MoveStrategy{
    
public:
    
    Minimax(std::string token){
        token_ = token;
    }
    int NextMove(Board);

private:
    
    const int MAX_DEPTH = 20;
    std::string token_;
    
    std::multimap<int, int> ScorePossibleMoves(Board);
    int HighestRatedMove(std::multimap<int, int>);
    std::string OtherToken(std::string);
    int ScoreMove(Board, int, std::string, int depth=1);
    int Maximize(Board, std::string, int);
    int Minimize(Board, std::string, int);
    bool Maximizing(std::string);
    int EvaluateGame(std::string, std::string, int);
};
#endif