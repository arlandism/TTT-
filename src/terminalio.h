#ifndef __TTT____terminalio__
#define __TTT____terminalio__

#include <string>
#include <iostream>
#include "io.h"

class TerminalIO: public IO{
    
public:
    
    std::string GetInput();
    void Print(std::string);
    
};
#endif
