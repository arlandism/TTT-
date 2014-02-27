#ifndef __TTT____mockplayer__
#define __TTT____mockplayer__

#include <iostream>
#include "player.h"
#include "vector"

class MockPlayer: public IPlayer {
    
public:
    
    MockPlayer(std::string token, std::vector<int> inputs_to_return){
        token_ = token;
        inputs_to_return_ = inputs_to_return;
    };
    
    int Move(Board board);
    std::string token();
    
private:
    std::vector<int> inputs_to_return_;
    std::string token_;
};

#endif
