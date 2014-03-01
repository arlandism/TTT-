#include "catch.hpp"
#include "board.h"
#include "movestrategy.h"
#include "mockmovestrategy.h"
#include "player.h"

TEST_CASE("Player..."){
    
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    
    SECTION("has supplied token"){
        std::string token = "X";
        Player *player = new Player(token, strategy);
        REQUIRE("X" == player->token());
    }
    
    SECTION("uses supplied input"){
        Board board = *new Board(3);
        std::string token = "X";
        Player *player = new Player(token, strategy);
        REQUIRE(1 == player->Move(board));
    }
}
