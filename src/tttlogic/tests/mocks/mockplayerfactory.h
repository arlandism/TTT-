#ifndef __TTT____mockplayerfactory__
#define __TTT____mockplayerfactory__

#include <string>
#include <vector>
#include "mockplayer.h"
#include "playerfactory.h"

class MockPlayerFactory: public IPlayerFactory {
    
public:
    
    IPlayer * Create(std::string, std::string);
    std::vector<std::string> ValidPlayerChoices();
    bool LastPlayerType(std::string);
    bool LastPlayerToken(std::string);
    bool FirstPlayerType(std::string);
    bool FirstPlayerToken(std::string);
    
private:
    
    std::vector<std::string> player_type_call_list;
    std::vector<std::string> player_token_call_list;
    
};
#endif
