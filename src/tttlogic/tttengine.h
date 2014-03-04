#ifndef __TTT____tttengine__
#define __TTT____tttengine__

#include <iostream>
#include "gamepresenter.h"
#include "tttrules.h"
#include "game.h"
#include "io.h"
#include "inputvalidator.h"
#include "player.h"
#include "uidriver.h"

class TTTEngine {
    
public:
    
    TTTEngine(IO *io, UIDriver *driver){
        io_ = io;
        driver_ = driver;
    }
    
    void StartGame();
    
private:
    IO *io_;
    UIDriver *driver_;
    std::vector<std::string> valid_player_choices = {"Human", "AI"};
    std::vector<std::string> valid_token_choices = {"x", "o"};
};
#endif
