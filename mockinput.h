#ifndef __TTT____mockinput__
#define __TTT____mockinput__
#include "input.h"
#include "vector"

class MockInput: public Input{
public:
    std::vector<int>inputsToReturn;
    
    MockInput(std::vector<int> toReturn){
        inputsToReturn = toReturn;
    };
    
    int call();
};

#endif
