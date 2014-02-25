#include "catch.hpp"
#include "mockmovestrategy.h"
#include "player.h"

TEST_CASE("Player generates players..." "[player]"){
    
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    
    SECTION("using supplied token"){
        std::string token = "X";
        Player *player = new Player(token, strategy);
        REQUIRE("X" == player->token());
    }
    
    SECTION("using supplied input"){
        std::string token = "X";
        std::vector<int> board = std::vector<int>();
        Player *player = new Player(token, strategy);
        REQUIRE(1 == player->Move(board));
    }
}