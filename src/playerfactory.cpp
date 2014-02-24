#include "playerfactory.h"

Player * PlayerFactory::Create(MoveStrategy *strategy, std::string token){
    return new Player("X");
}