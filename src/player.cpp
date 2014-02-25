#include "player.h"

std::string Player::token (){
    return token_;
}

int Player::Move(std::vector<int> board){
    return move_strategy_->NextMove(board);
}

