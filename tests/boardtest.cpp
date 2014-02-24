#include "catch.hpp"
#include "board.h"

TEST_CASE("Board reports the winner", "[board]"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(2, "x");
    board.Move(3, "x");
    REQUIRE("x" == board.winner());
}

TEST_CASE("Board returns NO WINNER for no winner", "[board]"){
    Board board = *new Board(3);
    board.Move(1, "x");
    board.Move(3, "x");
    REQUIRE("NO WINNER" == board.winner());
}