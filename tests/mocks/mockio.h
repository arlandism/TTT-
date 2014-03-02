#ifndef __TTT____mockio__
#define __TTT____mockio__
#include "io.h"
#include <iostream>
#include "vector"

class MockIO: public IO {
public:
    
    MockIO(std::vector<std::string> to_return){
        inputs_to_return = to_return;
    };
    
    std::string GetInput();
    
private:
    std::vector<std::string>inputs_to_return;
};

#endif