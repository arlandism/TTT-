#include "catch.hpp"
#include "mockmovestrategy.h"
#include "playerfactory.h"

TEST_CASE("PlayerFactory generates players using supplied token" "[playerfactory]"){
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    std::string token = "X";
    Player *player = PlayerFactory::Create(strategy, token);
    REQUIRE("X" == player->token());
}

TEST_CASE("PlayerFactory generates players using supplied move strategy" "[playerfactory]"){
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    std::string token = "X";
    Player *player = PlayerFactory::Create(strategy, token);
    REQUIRE(1 == player->Move());
}