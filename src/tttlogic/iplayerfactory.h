#ifndef TTT___iplayerfactory_h
#define TTT___iplayerfactory_h

#include "iplayer.h"

class IPlayerFactory {
    
public:
    
    virtual IPlayer * Create(std::string, std::string)=0;
};


#endif
