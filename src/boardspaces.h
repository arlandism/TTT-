#ifndef __TTT____boardspaces__
#define __TTT____boardspaces__

#include <iostream>
#include "math.h"
#include "vector"

class BoardSpaces {
    
public:
    
    BoardSpaces(std::vector<std::string> board_state){
        state_ = board_state;
        base_ = sqrt(state_.size());
    }
    
    std::vector<std::vector<std::string>> Rows();
    
private:
    std::vector<std::string> state_;
    int base_;
};
#endif
