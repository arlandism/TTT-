#ifndef TTT___playerfactory_h
#define TTT___playerfactory_h

#include "player.h"
#include "consolemovestrategy.h"
#include "minimax.h"
#include "movestrategy.h"
#include "iplayerfactory.h"
#include <vector>
#include <string>

class PlayerFactory: public IPlayerFactory {
    
public:
    
    std::vector<std::string> ValidPlayerChoices();
    IPlayer * Create(std::string, std::string);
};

#endif
