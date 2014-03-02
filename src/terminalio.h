#ifndef __TTT____terminalio__
#define __TTT____terminalio__

#include "io.h"
#include <iostream>

class TerminalIO: public IO {
    
    std::string GetInput();
    void Print(std::string);
    
};
#endif
