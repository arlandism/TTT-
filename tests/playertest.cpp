#include "catch.hpp"
#include "board.h"
#include "movestrategy.h"
#include "mockmovestrategy.h"
#include "player.h"

TEST_CASE("Player generates players..."){
    
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    
    SECTION("using supplied token"){
        std::string token = "X";
        Player *player = new Player(token, strategy);
        REQUIRE("X" == player->token());
    }
    
    SECTION("using supplied input"){
        Board board = *new Board(3);
        std::string token = "X";
        Player *player = new Player(token, strategy);
        REQUIRE(1 == player->Move(board));
    }
}