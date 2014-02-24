#ifndef TTT___player_h
#define TTT___player_h
#include <iostream>
#include "movestrategy.h"

class Player {

public:
    Player(std::string token, MoveStrategy * strategy) {
        token_ = token;
        move_strategy_ = strategy;
    };
    
    std::string token();
    int Move(std::vector<int>);
    
private:
    std::string token_;
    MoveStrategy *move_strategy_;
};

#endif