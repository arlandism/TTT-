#ifndef __TTT____board__
#define __TTT____board__

#include <iostream>
#include "vector"

class Board{
    
public:
    Board(int base){
        base_ = base;
        const int numSpaces_ = base * base;
        state_ = *new std::vector<std::string>(numSpaces_);
    }
    
    void Move(int, std::string);
    std::string winner();
    
private:
    const std::string NO_WINNER_ = "NO WINNER";
    std::vector<std::string> state_;
    std::string winner_;
    int base_;
    
    bool AllEqual(std::vector<std::string>);
    std::vector<std::vector<int>> Rows();
    std::vector<std::vector<int>> Columns();
    std::vector<std::vector<int>> Diagonals();
    std::vector<int> Range(int);
};
#endif
