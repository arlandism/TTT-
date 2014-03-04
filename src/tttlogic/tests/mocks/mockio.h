#ifndef __TTT____mockio__
#define __TTT____mockio__

#include <string>
#include <vector>
#include "io.h"

class MockIO: public IO {
    
public:
    
    MockIO(){};
    
    MockIO(std::vector<std::string> to_return){
        inputs_to_return = to_return;
    };
    
    std::string GetInput();
    void Print(std::string);
    
private:
    
    std::vector<std::string>inputs_to_return;
};

#endif