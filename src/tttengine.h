#ifndef __TTT____tttengine__
#define __TTT____tttengine__

#include <iostream>
#include "gamepresenter.h"
#include "minimax.h"
#include "tttsettings.h"
#include "terminalinput.h"
#include "game.h"
#include "player.h"

class TTTEngine {
    
public:
    
    std::vector<std::string> valid_player_choices = {"Human", "AI"};
    std::vector<std::string> valid_token_choices = {"x", "o"};
    
    void StartGame(std::string, std::string, std::string, std::string);
    bool AffirmativeAnswer(std::string);
    
private:
    
    Player * CreatePlayer(std::string player_type, std::string player_token);
};
#endif
