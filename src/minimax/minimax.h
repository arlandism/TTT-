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
    std::multimap<int, int> ScorePossibleMoves(Board);
    int ScoreMove(Board, int, std::string, bool maximizing=true);
    int Maximize(Board, std::string);
    int Minimize(Board, std::string);
    std::string GameWinner(Board);
    bool GameOver(Board);
    int HighestRatedMove(std::multimap<int, int>);
    int EvaluateGame(std::string, std::string);
    std::string token_;
};
#endif