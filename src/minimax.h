#ifndef __TTT____minimax__
#define __TTT____minimax__

#include <iostream>
#include "movestrategy.h"
#include "vector"

class Minimax:public MoveStrategy{
    
public:
    Minimax(std::string token){
        token_ = token;
    };
    int NextMove(std::vector<int>);
    
private:
    std::string token_;
};
#endif
