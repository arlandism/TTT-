#include "board.h"

void Board::Move(int space, std::string token){
    state_[space - 1] = token;
}

std::string Board::winner(){
    std::vector<std::string>rowOne = {state_[0], state_[1], state_[2]};
    if (AllEqual(rowOne)){
        return state_[0];
    };
    return NO_WINNER_;
}

bool Board::AllEqual(std::vector<std::string> collection){
    return std::equal(collection.begin() + 1, collection.end(), collection.begin());
}

std::vector<std::vector<int>> Board::Rows(){
    std::vector<std::vector<int>> rows;
    for (int i = 0; i < base_; i++ ){
        std::vector<int> row = {i, i, i};
        rows[i] = row;
    }
    return rows;
};

std::vector<std::vector<int>> Board::Columns(){
    return *new std::vector<std::vector<int>>();
};

std::vector<std::vector<int>> Board::Diagonals(){
     return *new std::vector<std::vector<int>>();
};

std::vector<int> Board::Range(int upperBound){
    std::vector<int> range;
    for (int i = 0; i < upperBound; i++){
        range[i] = i;
    }
    return range;
}