#ifndef __TTT____playerfactory__
#define __TTT____playerfactory__

#include "movestrategy.h"
#include "player.h"
#include <iostream>

class PlayerFactory{

public:
    static Player Create(MoveStrategy* strategy, std::string token);
};

#endif
