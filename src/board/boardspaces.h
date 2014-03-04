#ifndef __TTT____boardspaces__
#define __TTT____boardspaces__

#include <string>
#include <vector>
#include "math.h"

class BoardSpaces{
    
public:
    
    BoardSpaces(std::vector<std::string> board_state){
        state_ = board_state;
        base_ = sqrt(state_.size());
    }
    
    std::vector<std::vector<std::string>> Rows();
    std::vector<std::vector<std::string>> Columns();
    std::vector<std::vector<std::string>> Diagonals();
    
private:
    
    std::vector<std::string> state_;
    int base_;
    std::vector<std::string> DiagonalOne();
    std::vector<std::string> DiagonalTwo();
};
#endif
