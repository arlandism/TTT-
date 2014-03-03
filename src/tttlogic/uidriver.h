#ifndef __TTT____uidriver__
#define __TTT____uidriver__

#include <iostream>
#include "iplayer.h"
#include "playerfactory.h"
#include "gamepresenter.h"
#include "inputvalidator.h"
#include "io.h"
#include "vector"

class UIDriver {
    
public:
    
    UIDriver(IO *io, IPlayerFactory *factory){
        io_ = io;
        factory_ = factory;
    }
    
    IPlayer * CreatePlayer(std::string player_type, std::string player_token);
    std::string GetPlayerType(std::vector<std::string>);
    std::string GetToken(std::vector<std::string>);
    
private:
    
    IO *io_;
    IPlayerFactory *factory_;
    std::string used_token_;
    
    std::string GetFromUser(std::vector<std::string>, std::string);
};
#endif
