#ifndef __TTT____mockinput__
#define __TTT____mockinput__
#include "input.h"

class MockInput: public Input {
public:
    virtual ~MockInput();
    MockInput(int toReturn[]);
    
    virtual int call();

};

#endif
