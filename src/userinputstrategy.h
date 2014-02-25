#ifndef __TTT____userinputstrategy__
#define __TTT____userinputstrategy__

#include "movestrategy.h"
#include "vector"

class UserInputStrategy: public MoveStrategy {
    
public:
    int NextMove(std::vector<int>);
    
};
#endif