#ifndef TTT___player_h
#define TTT___player_h

#include <string>
#include "board.h"
#include "movestrategy.h"
#include "iplayer.h"

class Player: public IPlayer {

public:
    
    Player(std::string token, MoveStrategy * strategy) {
        token_ = token;
        move_strategy_ = strategy;
    };
    
    std::string token();
    int Move(Board board);
    
private:
    
    std::string token_;
    MoveStrategy *move_strategy_;
    
    bool ValidMove(Board, int);
};

#endif