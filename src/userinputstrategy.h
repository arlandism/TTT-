#ifndef __TTT____userinputstrategy__
#define __TTT____userinputstrategy__

#include "board.h"
#include "movestrategy.h"
#include "vector"

class UserInputStrategy: public MoveStrategy {
    
public:
    int NextMove(Board board);
    
};
#endif