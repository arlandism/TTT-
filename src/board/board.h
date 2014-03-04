#ifndef __TTT____board__
#define __TTT____board__

#include <string>
#include <vector>
#include "boardspaces.h"

class Board{
    
public:
    
    Board(int base){
        base_ = base;
        const int numSpaces_ = base * base;
        state_ = *new std::vector<std::string>(numSpaces_);
    }
    
    Board(std::vector<std::string> state){
        state_ = state;
    }
    
    static const std::string EmptySpace;
    
    void Move(int, std::string);
    bool Full();
    bool AllSpacesFilledInCombination(std::vector<std::string>);
    std::vector<int> OpenSpaces();
    std::vector<std::string> state();
    
private:
    
    std::vector<std::string> state_;
    int base_;
    
    bool EmptySquarePresent(std::vector<std::string>);
};
#endif
