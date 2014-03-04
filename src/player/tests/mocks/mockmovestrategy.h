
#ifndef __TTT____mockmovestrategy__
#define __TTT____mockmovestrategy__

#include <string>
#include <vector>
#include "board.h"
#include "movestrategy.h"

class MockMoveStrategy: public MoveStrategy {
    
public:
    
    MockMoveStrategy(std::vector<int> to_return){
        inputs_to_return = to_return;
    }
    
    int NextMove(Board board);
    
private:
    std::vector<int>inputs_to_return;
};
#endif