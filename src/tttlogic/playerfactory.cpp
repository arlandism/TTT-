#include "playerfactory.h"

IPlayer * PlayerFactory::Create(std::string type, std::string token){
    MoveStrategy *move_strategy;
    if (type == "human"){
        move_strategy = new ConsoleMoveStrategy();
    } else {
        move_strategy = new Minimax(token);
    }
    return new Player(token, move_strategy);
}