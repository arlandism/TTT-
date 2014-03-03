#ifndef TTT___playerfactory_h
#define TTT___playerfactory_h

#include "player.h"
#include "consolemovestrategy.h"
#include "minimax.h"
#include "tttsettings.h"
#include "movestrategy.h"
#include "iplayerfactory.h"

class PlayerFactory: public IPlayerFactory {
    
public:
    
    IPlayer * Create(std::string, std::string);
};

#endif
