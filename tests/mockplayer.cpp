#include "mockplayer.h"

int MockPlayer::Move(Board board){
    int next_output_value = inputs_to_return_.back();
    inputs_to_return_.pop_back();
    return next_output_value;
}

std::string MockPlayer::token(){
    return token_;
}