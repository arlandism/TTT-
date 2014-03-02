#include "mockplayerfactory.h"

IPlayer * MockPlayerFactory::Create(std::string player_type, std::string token){
    player_type_call_list.push_back(player_type);
    player_token_call_list.push_back(token);
    return new MockPlayer();
}

bool MockPlayerFactory::LastPlayerType(std::string player_type){
    std::string last_call_value = player_type_call_list.back();
    return last_call_value == player_type;
}

bool MockPlayerFactory::LastPlayerToken(std::string token){
    std::string last_call_value = player_token_call_list.back();
    return last_call_value == token;
}