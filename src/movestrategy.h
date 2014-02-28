#ifndef __TTT____movestrategy__
#define __TTT____movestrategy__

#include "board.h"

class MoveStrategy {
    
public:
    
    virtual int NextMove(Board board)=0;
};

#endif