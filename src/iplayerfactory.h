#ifndef TTT___iplayerfactory_h
#define TTT___iplayerfactory_h

#include "player.h"

class IPlayerFactory {
    
public:
    
    virtual IPlayer * Create(std::string, std::string)=0;
};


#endif
