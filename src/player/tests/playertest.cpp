#include "catch.hpp"
#include "board.h"
#include "movestrategy.h"
#include "mockmovestrategy.h"
#include "player.h"

TEST_CASE("Player..."){
    
    std::vector<int> inputsToReturn = {1};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    
    SECTION("has supplied token"){
        std::string token = "x";
        Player *player = new Player(token, strategy);
        REQUIRE("x" == player->token());
    }
    
    SECTION("uses supplied input"){
        Board board = *new Board(3);
        std::string token = "x";
        Player *player = new Player(token, strategy);
        REQUIRE(1 == player->Move(board));
    }
}

TEST_CASE("Player doesn't allow moves not available on the board"){
    int first_move = 0;
    int second_move = 2;
    std::vector<int> inputsToReturn = {second_move, first_move};
    MoveStrategy *strategy = new MockMoveStrategy(inputsToReturn);
    Board board = *new Board(2);
    std::string token = "o";
    Player *player = new Player(token, strategy);
    REQUIRE(2 == player->Move(board));
}

TEST_CASE("Player "){
    
}
