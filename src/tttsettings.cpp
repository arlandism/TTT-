#include "tttsettings.h"

std::string TTTSettings::OtherToken(std::string token){
    if (token == token_two){
        return token_one;
    }
    return token_two;
}