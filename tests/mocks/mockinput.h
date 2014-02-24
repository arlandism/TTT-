#ifndef __TTT____mockinput__
#define __TTT____mockinput__
#include "input.h"
#include "vector"

class MockInput: public Input{
public:
    
    MockInput(std::vector<int> toReturn){
        inputsToReturn = toReturn;
    };
    
    int Call();
    
private:
    std::vector<int>inputsToReturn;
};

#endif
