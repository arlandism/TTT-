#ifndef __TTT____tttsettings__
#define __TTT____tttsettings__

#include <iostream>
#include "gamesettings.h"

class TTTSettings: public GameSettings {
    
public:
    
    TTTSettings(std::string token_one, std::string token_two){
        token_one_ = token_one;
        token_two_ = token_two;
    }
    
    std::string OtherToken(std::string);
    
private:
    
    std::string token_one_;
    std::string token_two_;
};
#endif