#ifndef TTT___iplayerfactory_h
#define TTT___iplayerfactory_h

#include "iplayer.h"
#include <vector>
#include <string>

class IPlayerFactory {
    
public:
    
    virtual IPlayer * Create(std::string, std::string)=0;
    virtual std::vector<std::string> ValidPlayerChoices()=0;
};


#endif
