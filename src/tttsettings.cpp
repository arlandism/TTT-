#include "tttsettings.h"

std::string TTTSettings::OtherToken(std::string token){
    if (token == token_two_){
        return token_one_;
    }
    return token_two_;
}