#ifndef __TTT____tttengine__
#define __TTT____tttengine__

#include <iostream>
#include "gamepresenter.h"
#include "minimax.h"
#include "tttsettings.h"
#include "game.h"
#include "io.h"
#include "inputvalidator.h"
#include "playerfactory.h"
#include "player.h"

class TTTEngine {
    
public:
    
    TTTEngine(IO *io){
        io_ = io;
        factory_ = new PlayerFactory();
    }
    
    TTTEngine(IO *io, PlayerFactory *factory){
        io_ = io;
        factory_ = factory;
    }
    
    std::vector<std::string> valid_player_choices = {"Human", "AI"};
    std::vector<std::string> valid_token_choices = {"x", "o"};
    
    void StartGame();
    std::string GetPlayerType();
    std::string GetToken();
    bool AffirmativeAnswer(std::string);
    
private:
    
    IO *io_;
    PlayerFactory *factory_;
    
    std::string GetFromUser(std::vector<std::string>, std::string);
    Player * CreatePlayer(std::string player_type, std::string player_token);
};
#endif
