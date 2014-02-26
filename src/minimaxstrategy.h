#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "movestrategy.h"
#include "vector"

class MinimaxStrategy:public MoveStrategy {
    
public:
    MinimaxStrategy(){};
    int NextMove(std::vector<int>);
    void set_token(std::string);

private:
    std::string token_;
};
#endif
