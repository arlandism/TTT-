#include "player.h"

std::string Player::token (){
    return token_;
}

int Player::Move(Board board){
    return move_strategy_->NextMove(board);
}

