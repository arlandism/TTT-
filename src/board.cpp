#include "board.h"

void Board::Move(int space, std::string token){
    state_[space - 1] = token;
}

std::string Board::winner(){
    if ((state_[0] == state_[1]) && (state_[1] == state_[2])){
        return state_[0];
    };
    return NO_WINNER_;
}
