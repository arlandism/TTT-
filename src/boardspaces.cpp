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
        
        int column_space = i;
        std::vector<std::string> column;
        
        for (int j = 0; j < base_; j++){
            column.push_back(state_[column_space]);
            column_space += base_;
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
    for (int diagonal_space = 0; diagonal_space < upper_bound; diagonal_space+= offset){
        diagonal_one.push_back(state_[diagonal_space]);
    }
    return diagonal_one;
}

std::vector<std::string> BoardSpaces::DiagonalTwo(){
    std::vector<std::string> diagonal_two;
    int start = base_ - 1;
    int upper_bound = base_ * base_ - 1;
    int offset = base_ - 1;
    for (int diagonal_space = start; diagonal_space < upper_bound; diagonal_space+= offset){
        diagonal_two.push_back(state_[diagonal_space]);
    }
    return diagonal_two;
}