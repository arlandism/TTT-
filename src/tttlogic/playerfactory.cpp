#include "playerfactory.h"

IPlayer * PlayerFactory::Create(std::string type, std::string token){
    MoveStrategy *move_strategy;
    if (type == "Human"){
        move_strategy = new ConsoleMoveStrategy(token);
    } else {
        move_strategy = new Minimax(token);
    }
    return new Player(token, move_strategy);
}

std::vector<std::string> PlayerFactory::ValidPlayerChoices(){
    std::vector<std::string> valid_player_choices = {"Human", "AI"};
    return valid_player_choices;
}