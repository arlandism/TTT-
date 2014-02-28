#ifndef __TTT____tttsettings__
#define __TTT____tttsettings__

#include <iostream>
#include "gamesettings.h"

class TTTSettings: public GameSettings {
    
public:
    
    static std::string token_one;
    static std::string token_two;
    
    static std::string OtherToken(std::string);
    static void set_token_one(std::string token){
        token_one = token;
    }
    static void set_token_two(std::string token){
        token_two = token;
    }
};
#endif