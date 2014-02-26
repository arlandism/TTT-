#include "boardspaces.h"

std::vector<std::vector<std::string>> BoardSpaces::Rows(){
    std::vector<std::vector<std::string>> rows;
    for(int i = 0, offset = 0; i < base_; i++, offset += base_){
        std::vector<std::string>::const_iterator start = state_.begin() + offset;
        std::vector<std::string>::const_iterator end = start + base_;
        std::vector<std::string> row = std::vector<std::string>(start, end);
        rows.push_back(row);
    }
    return rows;
}

std::vector<std::vector<std::string>> BoardSpaces::Columns(){
    std::vector<std::vector<std::string>> columns;
    for (int i = 0; i < base_; i++){
        int index = i;
        std::vector<std::string> column;
        for (int j = 0; j < base_; j++){
            column.push_back(state_[index]);
            index += base_;
        }
        columns.push_back(column);
    }
    return columns;
}

std::vector<std::vector<std::string>> BoardSpaces::Diagonals(){
    std::vector<std::vector<std::string>> diagonals;
    std::vector<std::string> diagonal_one = DiagonalOne();
    std::vector<std::string> diagonal_two = DiagonalTwo();
    diagonals = {diagonal_one, diagonal_two};
    return diagonals;
}

std::vector<std::string> BoardSpaces::DiagonalOne(){
    std::vector<std::string> diagonal_one;
    int upper_bound = base_ * base_;
    int offset = base_ + 1;
    for (int i = 0; i < upper_bound; i+= offset){
        diagonal_one.push_back(state_[i]);
    }
    return diagonal_one;
}

std::vector<std::string> BoardSpaces::DiagonalTwo(){
    std::vector<std::string> diagonal_two;
    int start = base_ - 1;
    int upper_bound = base_ * base_ - 1;
    int offset = base_ - 1;
    for (int i = start; i < upper_bound; i+= offset){
        diagonal_two.push_back(state_[i]);
    }
    return diagonal_two;
}

//vector<vector<string>> BoardSpaces::Diagonals(Board board){
//    vector<vector<string>> diagonals;
//    vector<string> diagonalOne = BoardSpaces::DiagonalOne(board);
//    vector<string> diagonalTwo = BoardSpaces::DiagonalTwo(board);
//    diagonals = {diagonalOne, diagonalTwo};
//    return diagonals;
//}
//
//vector<string> BoardSpaces::DiagonalOne(Board board){
//    vector<string> diagonalOne;
//    int upperBound = board.base() * board.base();
//    int offset = board.base() + 1;
//    for (int i = 0; i < upperBound; i+= offset){
//        diagonalOne.push_back(board.state()[i]);
//    }
//    return diagonalOne;
//}
//
////vector<string> BoardSpaces::DiagonalTwo(Board board){
//    vector<string> diagonalTwo;
//    int start = board.base() - 1;
//    int upperBound = board.base() * board.base() - 1;
//    int offset = board.base() - 1;
//    for (int i = start; i < upperBound; i+= offset){
//        diagonalTwo.push_back(board.state()[i]);
//    }
//    return diagonalTwo;
//}