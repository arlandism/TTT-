#include "mockplayerfactory.h"

//IPlayer * MockPlayerFactory::Create(std::string type, std::string token){
//    std::vector<int> moves = {1, 2, 3};
//    IPlayer *player = new MockPlayer();
//    return player;
//}

bool MockPlayerFactory::LastPlayerTypeCalledWith(std::string type){
    std::string last_call = *(player_type_call_list.end() - 1);
    return type == last_call;
}

bool MockPlayerFactory::LastPlayerTokenCalledWith(std::string type){
    std::string last_call = *(player_token_call_list.end() - 1);
    return type == last_call;
}