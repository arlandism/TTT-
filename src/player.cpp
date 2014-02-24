#include "player.h"

std::string Player::token (){
    return token_;
}

int Player::Move(){
    return move_strategy_->NextMove();
}
