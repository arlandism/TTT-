#ifndef __TTT____mockplayerfactory__
#define __TTT____mockplayerfactory__

#include <iostream>
#include "mockplayer.h"
#include "playerfactory.h"

class MockPlayerFactory: public IPlayerFactory {
    
public:
    
    IPlayer * Create(std::string, std::string);
    bool LastPlayerType(std::string);
    bool LastPlayerToken(std::string);
    
private:
    
    std::vector<std::string> player_type_call_list;
    std::vector<std::string> player_token_call_list;
    
};
#endif
