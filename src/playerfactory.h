#ifndef TTT___playerfactory_h
#define TTT___playerfactory_h

#include "player.h"
#include "terminalinput.h"
#include "minimax.h"
#include "tttsettings.h"
#include "movestrategy.h"

class PlayerFactory {
    
    IPlayer * Create(std::string, std::string);
};

#endif
