#ifndef __TTT____tttsettings__
#define __TTT____tttsettings__

#include <iostream>
#include "gamesettings.h"

class TTTSettings: public GameSettings {
    
public:
    
    std::string token_one;
    std::string token_two;
    
    std::string OtherToken(std::string);
};
#endif