#ifndef __TTT____mockplayerfactory__
#define __TTT____mockplayerfactory__

#include <iostream>
#include "playerfactory.h"
#include "mockplayer.h"
#include "map"
#include "vector"

class MockPlayerFactory : public PlayerFactory {
  
public:
    
//    IPlayer * Create(std::string, std::string);
    bool LastPlayerTypeCalledWith(std::string);
    bool LastPlayerTokenCalledWith(std::string);
    
private:
    
    std::vector<std::string> player_type_call_list;
    std::vector<std::string> player_token_call_list;
};
#endif