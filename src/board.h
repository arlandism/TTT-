#ifndef __TTT____board__
#define __TTT____board__

#include <iostream>
#include "vector"

class Board{
    
public:
    Board(int base){
        base_ = base;
        state_ = std::vector<std::string>(base * base);
    }
    
    void Move(int, std::string);
    std::string winner();
    
private:
    int base_;
    const std::string NO_WINNER_ = "NO WINNER";
    std::vector<std::string> state_;
    std::string winner_;
};
#endif
