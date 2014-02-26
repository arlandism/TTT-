#include "board.h"

void Board::Move(int space, std::string token){
    state_[space - 1] = token;
}

std::string Board::winner(){
    std::vector<std::vector<std::string>> rows = Rows();
    for (std::vector<std::vector<std::string>>::const_iterator it = rows.begin(); it != rows.end(); it++){
        std::vector<std::string> row = *it;
        if (AllEqual(row) && AllSpacesFilled(row)){
            return (*it).front();
        }
    }
    return NO_WINNER_;
}

bool Board::AllEqual(std::vector<std::string> collection){
    return std::equal(collection.begin() + 1, collection.end(), collection.begin());
}

bool Board::AllSpacesFilled(std::vector<std::string> spaces){
    return not EmptySquarePresent(spaces);
}

std::vector<std::vector<std::string>> Board::Rows(){
    BoardSpaces board_spaces = *new BoardSpaces(state_);
    return board_spaces.Rows();
};

std::vector<std::vector<int>> Board::Columns(){
    return *new std::vector<std::vector<int>>();
};

std::vector<std::vector<int>> Board::Diagonals(){
     return *new std::vector<std::vector<int>>();
};

bool Board::EmptySquarePresent(std::vector<std::string> spaces){
    std::string empty_square = "";
    return std::find(spaces.begin(), spaces.end(), empty_square) != spaces.end();
}