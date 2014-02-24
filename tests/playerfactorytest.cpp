#include "catch.hpp"
#include "mockmovestrategy.h"
#include "player.h"
#include "playerfactory.h"
#include "vector"

TEST_CASE("PlayerFactory generates players using supplied token" "[playerfactory]"){
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    std::string token = "X";
   // Player player = PlayerFactory::Create(strategy, token);
   // REQUIRE("X" == player.token);
}
