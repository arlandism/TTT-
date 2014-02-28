#ifndef __TTT____tttconsoleengine__
#define __TTT____tttconsoleengine__

#include <iostream>
#include "gamepresenter.h"
#include "minimax.h"
#include "tttsettings.h"
#include "terminalinput.h"
#include "game.h"
#include "player.h"

class TTTConsoleEngine {
    
public:
    
    Player * CreatePlayer();
    void StartGame(std::string, std::string, std::string, std::string);
    void PromptForReplay();
    
    std::vector<std::string> valid_player_choices = {"Human", "AI"};
};
#endif
