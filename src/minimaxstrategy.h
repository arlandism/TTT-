#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "board.h"
#include "movestrategy.h"
#include "vector"

class MinimaxStrategy:public MoveStrategy {
    
public:
    int NextMove(Board board);
    void set_token(std::string);

private:
    std::string token_;
};
#endif
