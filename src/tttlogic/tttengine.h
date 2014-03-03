#ifndef __TTT____tttengine__
#define __TTT____tttengine__

#include <iostream>
#include "gamepresenter.h"
#include "tttrules.h"
#include "game.h"
#include "io.h"
#include "inputvalidator.h"
#include "iplayerfactory.h"
#include "player.h"

class TTTEngine {
    
public:
    
    TTTEngine(IO *io, IPlayerFactory *factory){
        io_ = io;
        factory_ = factory;
    }
    
    void StartGame();
    bool AffirmativeAnswer(std::string);
    IPlayer * CreatePlayer(std::string player_type, std::string player_token);
    std::string GetPlayerType();
    std::string GetToken();
    
private:
    IO *io_;
    IPlayerFactory *factory_;
    std::string used_token_;
    std::vector<std::string> valid_player_choices = {"Human", "AI"};
    std::vector<std::string> valid_token_choices = {"x", "o"};
    
    std::string GetFromUser(std::vector<std::string>, std::string);
};
#endif
