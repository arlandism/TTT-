#ifndef TTT___iplayer_h
#define TTT___iplayer_h

#include <iostream>
#include "board.h"

class IPlayer {
    
public:
    
    virtual int Move(Board)=0;
    virtual std::string token()=0;
};


#endif