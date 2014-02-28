#ifndef __TTT____terminalinput__
#define __TTT____terminalinput__

#include "board.h"
#include "movestrategy.h"

class TerminalInput: public MoveStrategy {
    
public:
    
    int NextMove(Board);
};

#endif