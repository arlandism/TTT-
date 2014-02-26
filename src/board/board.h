#ifndef __TTT____board__
#define __TTT____board__

#include <iostream>
#include "vector"
#include "boardspaces.h"

class Board {
    
public:
    
    Board(int base){
        base_ = base;
        const int numSpaces_ = base * base;
        state_ = *new std::vector<std::string>(numSpaces_);
    }
    
    void Move(int, std::string);
    bool Full();
    bool AllSpacesFilled(std::vector<std::string>);
    std::vector<std::string> state();
    
private:
    
    std::vector<std::string> state_;
    int base_;
    
    bool EmptySquarePresent(std::vector<std::string>);
};
#endif
