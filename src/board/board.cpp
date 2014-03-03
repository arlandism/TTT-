#include "board.h"

const std::string Board::EmptySpace = "";

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
        if (token_at_space == EmptySpace){
            return false;
        }
    }
    return true;
}

std::vector<int> Board::OpenSpaces(){
    std::vector<int> open_spaces;
    std::vector<int>::const_iterator iterator;
    for (int index = 0; index < state_.size(); index++ ){
        std::string token = state_[index];
        if (token == EmptySpace){
            open_spaces.push_back(index + 1);
        }
    }
    return open_spaces;
}

void Board::Undo(int space){
    int square_index = space  - 1;
    state_[square_index] = EmptySpace;
}

bool Board::AllSpacesFilled(std::vector<std::string> spaces){
    return not EmptySquarePresent(spaces);
}

bool Board::EmptySquarePresent(std::vector<std::string> spaces){
    return std::find(spaces.begin(), spaces.end(), EmptySpace) != spaces.end();
}