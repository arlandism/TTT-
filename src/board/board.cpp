#include "board.h"

void Board::Move(int space, std::string token){
    int square_index = space - 1;
    state_[square_index] = token;
}

std::vector<std::string> Board::state(){
    return state_;
}

bool Board::Full(){
    std::vector<std::string>::const_iterator iterator;
    for (iterator = state_.begin(); iterator != state_.end(); iterator++){
        std::string token_at_space = *iterator;
        if (token_at_space != ""){
            return true;
        }
    }
    return false;
}

bool Board::AllSpacesFilled(std::vector<std::string> spaces){
    return not EmptySquarePresent(spaces);
}

bool Board::EmptySquarePresent(std::vector<std::string> spaces){
    std::string empty_square = "";
    return std::find(spaces.begin(), spaces.end(), empty_square) != spaces.end();
}