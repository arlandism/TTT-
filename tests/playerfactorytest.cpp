#include "catch.hpp"
#include "mockmovestrategy.h"
#include "playerfactory.h"

TEST_CASE("PlayerFactory generates players..." "[playerfactory]"){
    
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    
    SECTION("using supplied token"){
        std::string token = "X";
        Player *player = PlayerFactory::Create(strategy, token);
        REQUIRE("X" == player->token());
    }
    
    SECTION("using supplied input"){
        std::string token = "X";
        Player *player = PlayerFactory::Create(strategy, token);
        REQUIRE(1 == player->Move());
    }
    
}