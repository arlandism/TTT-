#ifndef __TTT____movestrategy__
#define __TTT____movestrategy__
#include "vector"

class MoveStrategy {
    
public:
    virtual int NextMove(std::vector<int>)=0;
};

#endif
