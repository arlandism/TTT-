#ifndef __TTT____mockplayer__
#define __TTT____mockplayer__

#include <iostream>
#include "player.h"
#include "vector"

class MockPlayer: public IPlayer {
    
public:
  
    MockPlayer(){
        std::vector<int> inputs_to_return = {1};
        token_ = "x";
        inputs_to_return_ = inputs_to_return;
    }
    
    MockPlayer(std::string token, std::vector<int> inputs_to_return){
        token_ = token;
        inputs_to_return_ = inputs_to_return;
    };
    
    int Move(Board board);
    std::vector<std::string> LastRecordedState();
    std::string token();
    
private:
    std::vector<int> inputs_to_return_;
    std::vector<std::vector<std::string>> recorded_board_states_;
    std::string token_;
    
    void RecordBoard(Board);
};

#endif