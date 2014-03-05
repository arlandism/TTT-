#ifndef TTT___playerfactory_h
#define TTT___playerfactory_h

#include <vector>
#include <string>
#include "player.h"
#include "consolemovestrategy.h"
#include "minimax.h"
#include "movestrategy.h"
#include "iplayerfactory.h"

class PlayerFactory: public IPlayerFactory{
    
public:
    
    std::vector<std::string> ValidPlayerChoices();
    IPlayer * Create(std::string, std::string);
};

#endif
