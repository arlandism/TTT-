
#ifndef __TTT____mockmovestrategy__
#define __TTT____mockmovestrategy__

#include <iostream>
#include "movestrategy.h"
#include "vector"

class MockMoveStrategy: public MoveStrategy{
public:
    MockMoveStrategy(std::vector<int> toReturn){
        inputsToReturn = toReturn;
    }
    
    int Execute();
    
private:
    std::vector<int>inputsToReturn;
    
};
#endif
