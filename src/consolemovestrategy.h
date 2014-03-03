#ifndef __TTT____consolemovestrategy__
#define __TTT____consolemovestrategy__

#include "board.h"
#include "movestrategy.h"

class ConsoleMoveStrategy: public MoveStrategy {
    
public:
    
    int NextMove(Board);
};

#endif